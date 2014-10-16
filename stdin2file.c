#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LENGTH 10
#define MESSAGELENGTH 30

int main(int argc, char *argv[])
{
    char message[LENGTH], string[LENGTH], filename[LENGTH];

    FILE *fp;
    strcpy(filename, argv[1]);
    if(filename[0] == '\0'){
        fprintf(stderr, "ファイル名が入力されていません。。\n");
        exit(-1);
    }
    strcat(filename, ".txt");

    fp = fopen(filename, "a");
    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
        exit (-1);
    }

    do{
        fputs("文字列を入力してください:" , stdout);
        fgets(string, sizeof(string), stdin);
        if(string[0] == '\n'){
            fprintf(stderr, "何も入力されていません。\n");
            continue;
        }
        if (strchr(string, '\n') != NULL) {
            string[LENGTH - 1] = '\0';
        } else {
            fprintf(stderr, "文字数が多すぎます。\n");
            // 入力ストリームをクリアする処理。
            while(getchar() != '\n');
            continue;
        }
        fputs(string, fp);
        fputs("文字をファイルに書き込みました\n", stdout);
        break;
    }while(1);

    fclose(fp);
    exit(0);
}
