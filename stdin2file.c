#include<stdio.h>
#include<stdlib.h>
#define FILENAME "filetest1.txt"
#define LENGTH 10

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(FILENAME, "a");
    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
        exit (-1);
    }

    char string[LENGTH];
    fputs("文字列を入力してください:" , stdout);
    fgets(string, sizeof(string), stdin);
    if(string[LENGTH - 1] == '\0'){
        fprintf(stdout, "文字が長過ぎます。10文字を越えているものは表示されません\n");
    }
    fputs(string, fp);
    fputs("文字列を書き込みました。\n", stdout);

    fclose(fp);
    exit(0);
}
~     
