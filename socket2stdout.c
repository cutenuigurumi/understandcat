#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#define MAX_BACKLOG 5
#define DEFAULT_PORT "50000"
#define BUF_LINE_SIZE 1024
#define FILENAME 50
#define TIME 20
#define METHOD_LEN 5
#define PATH_LEN 20
#define EXPLAIN_LEN 20
#define CONTENTTYPE_LEN 30
#define CHARASET_LEN 20
#define VERSION_LEN 10
#define CONTENT_LENGTH_LEN 10
#define EXTENSION_LEN 10
#define USER_INPUT_LEN 10
#define STATUSLINE_ARRAY 10
#define CODE_200 0
#define CODE_303 1
#define CODE_400 2
#define CODE_403 3
#define CODE_404 4
#define EXTENSION_ARRAY 10
#define PATH_400 "/usr/local/bin/scd_education/www/400.html"
#define PATH_403 "/usr/local/bin/scd_education/www/403.html"
#define PATH_404 "/usr/local/bin/scd_education/www/404.html"
#define FILE_HEAD "/request_"
#define EXTENSION ".log"
#define DOCUMENTROOT "/usr/local/bin/scd_education/www"
#define LOGFILETROOT "/usr/local/bin/scd_education/log"
#define DELETE_COOKIE_DATE "Thu, 1-Jan-1970 00:00:00 GMT;"
#define COOKIEVALUE1 "cookie_value1"
#define COOKIEVALUE2 "cookie_value2"
#define COOKIECREATE "/usr/local/bin/scd_education/www/cookie/login_check.html"
#define COOKIEDELETE "/usr/local/bin/scd_education/www/cookie/logout.html"
#define REDIRECT_LOCATION "http://54.64.221.93:50000/cookie/welcome.html"
#define ID_TEST "admin"
#define PASS_WORD_TEST "nmadmin001"

static int listen_socket (char *port);
struct statusline {
    char version[VERSION_LEN];
    int status_code;
    char explain[EXPLAIN_LEN];
};
struct extension_list {
    char extension[EXTENSION_LEN];
    char content_type[CONTENTTYPE_LEN];
    char charaset[CHARASET_LEN];
};


int main (int argc, char *argv[]) {
    int lissock;
    char filename[PATH_LEN], return_path[PATH_LEN], datetime[TIME], method[METHOD_LEN], *p_method, path[PATH_LEN], *p_path, version[VERSION_LEN], *p_version, content_length[CONTENT_LENGTH_LEN], *p_content_length, username[USER_INPUT_LEN], password[USER_INPUT_LEN], *p_username, *p_password;
    FILE *response;
    time_t now;
    struct tm *str_date;
    struct stat str_file;
    //ステータスラインの情報を格納する構造体
    struct statusline str_statusline[STATUSLINE_ARRAY] = {
        {"HTTP/1.0", 200, "OK"},
        {"HTTP/1.0", 303, "See Other"},
        {"HTTP/1.0", 400, "Bad Request"},
        {"HTTP/1.0", 403, "Forbidden"},
        {"HTTP/1.0", 404, "Not Found"},
    };
    //拡張子とcontent-typeを格納する構造体
    struct extension_list str_extension_list[EXTENSION_ARRAY] = {
        {".html", "text/html;", "charset=UTF-8"},
        {".htm", "text/html;", "charset=UTF-8"},
        {".txt", "text/plain;", "charset=UTF-8"},
        {".jpg", "image/jpeg", ""},
        {".jpeg", "image/jpeg", ""},
        {".ico", "image/x-icon", ""},
        {".gif", "image/gif", ""},
        {".png", "image/png", ""}
    };

    lissock = listen_socket (DEFAULT_PORT);
    for (;;) {
        struct sockaddr_storage addr;
        socklen_t addrlen = sizeof addr;
        int accsock, status_line_flag = 0, tmp_status_code = 0, tmp_content_type = 0,error_flag = 0, int_content_length = 0, continue_flag = 0;
        char buf_request[BUF_LINE_SIZE],buf[BUF_LINE_SIZE];
        FILE *fp, *sockf, *write_sockf;

        //logファイルの作成
        now = time(NULL);
        str_date = localtime(&now);
        strftime(datetime,  TIME, "%Y%m%d%H%M%S", str_date);
        strcpy(filename,  LOGFILETROOT);
        strcat(filename, FILE_HEAD);
        strcat(filename, datetime);
        strcat(filename, EXTENSION);

        //ソケットへの接続を待つ動作を用意する
        accsock = accept (lissock, (struct sockaddr*) &addr, &addrlen);
        if (accsock < 0) {
            fprintf (stderr, "accept failed\n");
            continue;
        }
        sockf = fdopen (accsock, "r");
        write_sockf = fdopen(accsock, "w");
        fp = fopen(filename, "w");
        //デバッグ
        int d = 0;
        /*ここからリクエストを読み込み(while文の中が1リクエスト)
         *解析したり、logに吐き出したりする  */
        while (fgets (buf, BUF_LINE_SIZE, sockf)) {
            if(status_line_flag == 0){
                //一時変数に格納
                strcpy(buf_request, buf);
                //リクエストラインの解析
                p_method = strtok(buf_request, " ");
                strcpy(method, p_method);
                p_path = strtok(NULL, " ");
                strcpy(path, p_path);
                p_version = strtok(NULL, " ");
                strcpy(version, p_version);
                status_line_flag = 1;
            }
            if(strstr(buf, "Content-Length:") != NULL){
                p_content_length = strtok(buf, ":");
                p_content_length = strtok(NULL, ":");
                strcpy(content_length, p_content_length);
            }
            fputs (buf, fp);
            if(strcmp(buf, "\r\n") == 0){
                if(strcmp(method, "POST") == 0){
                    fgets(buf, atoi(content_length), sockf);
                    fputs(buf, fp);
                    p_username = strtok(buf, "&");
                    strcpy(username, p_username);
                    p_password = strtok(NULL, "&");
                    strcpy(password, p_password);
                    break;
                }
                if(strcmp(method, "GET") == 0){
                    break;
                }
            }
        }
        char buffer[BUF_LINE_SIZE];

        //レスポンスを返す
        if(strcmp(path, "/") == 0){
            strcpy(path, "/index.html");
        }
        strcpy(return_path, DOCUMENTROOT);
        strcat(return_path, path);
        //400 badrequest ディレクトリトラバーサル対策
        if(strstr(return_path, "../") != NULL){
            strcpy(return_path, PATH_400);
            tmp_status_code = CODE_400;
            error_flag = 1;
        }

        //拡張子を取得
        char *extension = strstr(path, ".");
        //.が無かった時の処理を入れる
        int i, debug;
        for(i = 0; i < EXTENSION_ARRAY; i++){
            debug = strcmp(extension, str_extension_list[i].extension);
            if(debug == 0){
                tmp_content_type = i;
                break;
            }
        }
        //構造体の中に該当の拡張子が無かった時の処理を入れる。
        if(i < EXTENSION_ARRAY){
            error_flag = 1;
        }
        //Content-Lengthがあったら、return_pathを何回読めば良いかを計算する
//      int read_return_path_times = 0;
//      if(content_length != NULL){
//          int_content_length = atoi(content_length);
//          printf("デバッグcontent_length %d", int_content_length);
//          read_return_path_times = int_content_length / BUF_LINE_SIZE;
//          printf("デバッグ read_return_path_times: %d", read_return_path_times);
//      }

        int file_size = 0;
        struct stat file;
        //ブラウザに返すファイルを開く

        //404 該当するページが無かったときの処理
        if(stat(return_path, &str_file) != 0){
            strcpy(return_path, PATH_404);
            tmp_status_code = CODE_404;
            //tmp_content_type = CONTENT_TYPE_HTML;
            error_flag = 1;
        }
        int binary_flag = 0, text_flag = 0;
        if((strstr(str_extension_list[tmp_content_type].content_type, "image")) != NULL){
            response = fopen(return_path, "rb");
            if(response == NULL){
                printf("ひらけませんでした\n");
            } else {
            binary_flag = 1;
            //Content-Lengthで使用する文字数カウントの処理
            fseek(response, 0L, SEEK_END);
            file_size = ftell(response);
            fseek(response, 0L, SEEK_SET);
            }
        } else {
            response = fopen(return_path, "r");
            text_flag = 1;
        }
//        printf("binary_flag%d, textflag %d\n", binary_flag,text_flag);

//      printf("リダイレクト300");
        if(strcmp(return_path, COOKIECREATE) == 0){
            tmp_status_code = CODE_303;
        }

//      printf("403処理の前\n");
        //403 閲覧禁止の場合の処理
        if(response == NULL && error_flag == 0){
            tmp_status_code = CODE_403;
            strcpy(return_path, PATH_403);
            error_flag = 1;
            //上でパスを変更しているので開き直す
            response = fopen(return_path ,"r");
        }
//      printf("403処理のあと\n");


        if(error_flag == 0){
            tmp_status_code = CODE_200;
        }

        fprintf(write_sockf, "%s %d %s\n", str_statusline[tmp_status_code].version, str_statusline[tmp_status_code].status_code, str_statusline[tmp_status_code].explain);
        fprintf(write_sockf, "Date: Tue, 18 Nov 2014 11:58:01 GMT\n");
        fprintf(write_sockf, "Server: Apache\n");
        fprintf(write_sockf, "Keep-Alive:timeout=2, max=100\n");
        fprintf(write_sockf, "Last-Modified: Mon, 26 Nov 2012 14:35:57 GMT\n");
        fprintf(write_sockf, "ETag: \"1a4-4cf66d9f26e81\"\n");
        fprintf(write_sockf, "Accept-Ranges: bytes\n");
        if(tmp_status_code == CODE_303){
            fprintf(write_sockf, "Location:%s \n", REDIRECT_LOCATION);
        }
        //cookieの処理(login_check.html)
        int cookie_create_check;
        cookie_create_check = strcmp(return_path, COOKIECREATE);
        //printf("cookie_create_check= %d, return_path=\"%s\", COOKIECREATE=\"%s\"\n", cookie_create_check, return_path, COOKIECREATE);
        if(cookie_create_check == 0){
            fprintf(write_sockf, "Set-Cookie: CUSTOMER=%s; path=/cookie/;\n", COOKIEVALUE1);
        }
        //Cookieの設定(logout.html)
        int cookie_delete_check;
        cookie_delete_check = strcmp(return_path, COOKIEDELETE);
        //printf("cookie_delete_check= %d, return_path=%s, COOKIEDELETE=%s\n", cookie_delete_check, return_path, COOKIEDELETE);
        if(cookie_delete_check == 0){
            fprintf(write_sockf, "Set-Cookie: CUSTOMER=%s; expires=%s;", COOKIEVALUE1, DELETE_COOKIE_DATE);
        }

        if(binary_flag == 1){
            fprintf(write_sockf, "Content-Length: %d\n", file_size);
            fprintf(stdout, "Content-Length: %d\n", file_size);
        }
//        fprintf(write_sockf, "Content-Length: 420\n", file_size);
        fprintf(write_sockf, "Content-Type: %s\n", str_extension_list[tmp_content_type].content_type);
        fprintf(write_sockf, "\n");
        printf("メッセージボディ送信前\n");
        //バイナリデータの処理
        if(binary_flag == 1){
//          printf("binary_flagのif文の中\n");
            int size = 0, k = 0;
            size = fread(buffer, sizeof( unsigned char ), 10000, response);
            for(k = 0; k < size; k++){
                fputc(buffer[k], write_sockf);
            }
//          printf("バイナリーフラッグの中\n");
        }
//      printf("binary flagから外%d, txtflag %d", binary_flag,text_flag);
        if(text_flag == 1){
            while(fgets(buffer, sizeof(buffer), response)){
                fputs(buffer, write_sockf);
            }
                printf("text_flagの中\n");
        }
        fclose(write_sockf);
        fclose (sockf);
        fclose (response);
        fclose(fp);
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
    //getaddrinfoでstruct addrinfoにインターネットアドレスが格納される
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
