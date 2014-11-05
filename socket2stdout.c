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
#define PATH "/usr/local/bin/scd_education/bin/log/"
#define FILE_HEAD "request_"
#define EXTENSION ".log"
#define INDEX "/usr/local/bin/scd_education/www/index.html"
#define RESPONSE "response.txt"

static int listen_socket (char *port);

int main (int argc, char *argv[]) {
    int lissock;
    char filename[FILENAME], datetime[TIME];
    FILE *response;
    time_t now;
    struct tm *str_date;
    now = time(NULL);
    str_date = localtime(&now);
    strftime(datetime,  TIME, "%Y%m%d%H%M%S", str_date);

    strcpy(filename,  PATH);
    strcat(filename, FILE_HEAD);
    strcat(filename, datetime);
    strcat(filename, EXTENSION);

    lissock = listen_socket (DEFAULT_PORT);
    for (;;) {
        struct sockaddr_storage addr;
        socklen_t addrlen = sizeof addr;
        int accsock;
        char buf[BUF_LINE_SIZE];
        FILE *fp, *sockf, *write_sockf;

        //ソケットへの接続を待つ動作を用意する
        accsock = accept (lissock, (struct sockaddr*) &addr, &addrlen);
        if (accsock < 0) {
            fprintf (stderr, "accept failed\n");
            continue;
        }
        printf("いちばんめ\n");
        response = fopen(INDEX ,"r");
        sockf = fdopen (accsock, "r");
        write_sockf = fdopen(accsock, "w");
        fp = fopen(filename, "w");
        while (fgets (buf, sizeof(buf), sockf)) {
            if(strcmp(buf, "\r\n") == 0){
                printf("if文の中\n");
                break;
            }
            fputs (buf, stdout);
        }
        printf("出力直後\n");
        char buffer[200];
        while(fgets(buffer, sizeof(buffer), response)){
            fputs(buffer, write_sockf);
        }
        printf("httpレスポンス送信後\n");
        fclose(write_sockf);
        fclose (sockf);
        close (accsock);
    }
}

static int listen_socket (char *port) {
    struct addrinfo hints, *res, *ai;
    int err;

    memset (&hints, 0, sizeof (struct addrinfo));
    hints.ai_family = AF_INET; /* IPv4 */
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; /* Server Side */
    if ((err = getaddrinfo (NULL, port, &hints, &res)) != 0) {
        fprintf (stderr, "getaddrinfo error");
        exit (-1);
    }
    for (ai = res; ai; ai = ai->ai_next) {
        int sock;

        //fprintf (stdout, "ai_next:%i\n", ai);

        sock = socket (ai->ai_family, ai->ai_socktype, ai->ai_protocol);
        if (sock < 0) {
            fprintf (stdout, "cannot create socket\n");
            continue;
        }
        if (bind (sock, ai->ai_addr, ai->ai_addrlen) < 0) {
            close (sock);
            fprintf (stdout, "cannot bind socket\n");
            continue;
        }
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
