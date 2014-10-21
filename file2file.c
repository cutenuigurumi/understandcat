#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LENGTH 

int main(int argc, char *argv[])
{
    FILE *fpRead, *fpWrite;
    char c, readFilename[LENGTH], writeFilename[LENGTH];

    //引数の数チェック
    if(argc > 3){
        fprintf(stderr, "引数が多すぎます。\n");
        exit(-1);
    }
    if(argc < 1){
        fprintf(stderr, "引数が少なすぎます\n");
        exit(-1);
    }
    if(strlen(argv[1]) >= LENGTH){
        fprintf(stderr, "ファイル名が長過ぎます！\n終了します\n");
        exit(-1);
    }
    printf("%d", argc);
    strcpy(readFilename, argv[1]);
    strcpy(writeFilename, argv[2]);

    fpRead = fopen(readFilename, "r");
    if(fpRead == NULL){
        fprintf(stderr, "ファイルのオープンに失敗しました。\nファイルがありません\n");
        exit (-1);
    }
    fpWrite = fopen(writeFilename, "w");
    if(fpRead == NULL){
        fprintf(stderr, "ファイルのオープンに失敗しました。\nファイルがありません\n");
        //上でファイルのオープンに成功している可能性があるので閉じる。
        fclose(fpRead);
        exit (-1);
    }
    while(1){
        c = fgetc(fpRead);
        if(c == EOF){
            break;
        }
        fputc(c, fpWrite);
    }

    fclose(fpRead);
    fclose(fpWrite);
    exit(0);

}
