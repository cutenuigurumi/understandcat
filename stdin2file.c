#include<stdio.h>
#include<stdlib.h>
#define FILENAME "filetest1.txt"


int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(FILENAME, "a");
    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
        return -1;
    }

    char string[10];
    fputs("文字列を入力してください:" , stdout);
    fgets(string, sizeof(string), stdin);
    fprintf(fp, "%s\n", string);
    fputs("文字列を書き込みました。");

    fclose(fp);
    exit(0);
}
