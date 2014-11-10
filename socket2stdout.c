#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#define MAX_BACKLOG 5
#define DEFAULT_PORT "50000"
#define BUF_LINE_SIZE 1024
#define FILENAME 50
#define TIME 20
#define METHOD_LEN 5
#define PATH_LEN 20
#define STATUSCODE_LEN 10
#define PATH "/usr/local/bin/scd_education/bin/log/"
#define FILE_HEAD "request_"
#define EXTENSION ".log"
#define DOCUMENTROOT "/usr/local/bin/scd_education/www"
#define RESPONSE "response.txt"

static int listen_socket (char *port);

int main (int argc, char *argv[]) {
    int lissock;
    char filename[PATH_LEN], return_path[PATH_LEN], datetime[TIME], method[METHOD_LEN], *p_method, path[PATH_LEN], *p_path, statuscode[STATUSCODE_LEN], *p_statuscode;
    FILE *response;
    time_t now;
    struct tm *str_date;
    now = time(NULL);
    str_date = localtime(&now);
    strftime(datetime,  TIME, "%Y%m%d%H%M%S", str_date);

    //logファイルの作成
    strcpy(filename,  PATH);
    strcat(filename, FILE_HEAD);
    strcat(filename, datetime);
    strcat(filename, EXTENSION);

    lissock = listen_socket (DEFAULT_PORT);
    for (;;) {
        struct sockaddr_storage addr;
        socklen_t addrlen = sizeof addr;
        int accsock, status_line_flag = 0;
        char buf_request[BUF_LINE_SIZE],buf[BUF_LINE_SIZE];
        FILE *fp, *sockf, *write_sockf;

        //ソケットへの接続を待つ動作を用意する
        accsock = accept (lissock, (struct sockaddr*) &addr, &addrlen);
        if (accsock < 0) {
            fprintf (stderr, "accept failed\n");
            continue;
        }
        sockf = fdopen (accsock, "r");
        write_sockf = fdopen(accsock, "w");
        fp = fopen(filename, "a");
        while (fgets (buf, sizeof(buf), sockf)) {
            if(status_line_flag == 0){
                //ここでコピーしておかないと、下でstrtokしているのでリクエストラインの出力がうまくいかない。
                strcpy(buf_request, buf);
                //リクエストラインの解析
                p_method = strtok(buf_request, " ");
                strcpy(method, p_method);
                p_path = strtok(NULL, " ");
                strcpy(path, p_path);
                p_statuscode = strtok(NULL, " ");
                strcpy(statuscode, p_statuscode);
                status_line_flag = 1;
            }
            if(strcmp(buf, "\r\n") == 0){
                break;
            }
            fputs (buf, stdout);
        }
        char buffer[200];
        //レスポンスを返す
        if(strcmp(path, "/") == 0){
            strcpy(path, "/index.html");
        }

        strcpy(return_path, DOCUMENTROOT);
        strcat(return_path, path);
        response = fopen(return_path ,"r");
        fputs("HTTP/1.1 403 OK\n" , write_sockf);
        fputs("Content-Type: text/html; charset=shift_jis\n" , write_sockf);
        fputs("\n", write_sockf);
        while(fgets(buffer, sizeof(buffer), response)){
            fputs(buffer, write_sockf);
        }
        fclose(write_sockf);
        fclose (sockf);
        close (accsock);
    }
}

static int listen_socket (char *port) {
    struct addrinfo hints, *res, *ai;
    int err;

    //アドレス情報を設定する
    memset (&hints, 0, sizeof (struct addrinfo));
    //ネットワークアドレスの種類(IPv4)を格納
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; /* Server Side */
    /*getaddrinfoでstruct addrinfoにインターネットアドレスが格納される
    *成功したらerrの中には0が格納される */
    if ((err = getaddrinfo (NULL, port, &hints, &res)) != 0) {
        fprintf (stderr, "getaddrinfo error");
        exit (-1);
    }
    for (ai = res; ai; ai = ai->ai_next) {
        int sock;

        //fprintf (stdout, "ai_next:%i\n", ai);

        /*ソケットの作成
         *引数はどうやって通信するかを指定している。
         *sockにはソケットへのディスクリプタが格納される */
        sock = socket (ai->ai_family, ai->ai_socktype, ai->ai_protocol);
        if (sock < 0) {
            fprintf (stdout, "cannot create socket\n");
            continue;
        }
        /*アドレスを割り当てる*/
        if (bind (sock, ai->ai_addr, ai->ai_addrlen) < 0) {
            close (sock);
            fprintf (stdout, "cannot bind socket\n");
            continue;
        }
        /*listen クライアント側からの接続要求を待つ*/
        if (listen (sock, MAX_BACKLOG) < 0) {
            close (sock);
            fprintf (stdout, "cannot listen socket\n");
            continue;
        }
        freeaddrinfo (res);
        return sock;
    }

    fprintf (stderr, "failed to listen socket\n");
    exit (-1);
}
