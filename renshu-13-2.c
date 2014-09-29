#include<stdio.h>
#include<string.h>

int main()
{

    FILE *fp;
    char filename[10];
    int errorFlag = 0, filenameLength = 0;

    printf("ファイル名を入力して下さい\n");
    if(scanf("%s", filename) != 1){
        scanf("%*s");
        printf("入力エラーです。\n");
    }

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("%sというファイルは存在しません。\n", filename);
    } else {
        printf("%sというファイルは存在します。\n", filename);
    }
    fclose(fp);
}

