#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILENAME "filetest1.txt"
#define STRINGLENGTH 10
#define MESSAGELENGTH 30

int main(int argc, char *argv[])
{
    char message[MESSAGELENGTH];
    char string[STRINGLENGTH];

    FILE *fp;
    fp = fopen(FILENAME, "a");
    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
        exit (-1);
    }

    do{
        fputs("文字列を入力してください:" , stdout);
        fgets(string, sizeof(string), stdin);
        if(string[0] == '\n'){
            printf("何も入力されていません。\n");
            continue;
        }
        if (strchr(string, '\n') != NULL) {
            string[STRINGLENGTH - 1] = '\0';
        } else {
            printf("文字数が多すぎます。%s\n", string);
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
