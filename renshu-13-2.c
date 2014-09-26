#include<stdio.h>
#include<string.h>

int main()
{

    FILE *fp;
    char filename[256];

    printf("ファイル名を入力して下さい\n");
    fgets(filename, sizeof(filename), stdin);
    filename[strlen(filename) - 1] = '\0';

    fp = fopen("filename", "w");

    if(fp == NULL){
        printf("%sというファイルは存在しません。\n", filename);
    } else {
        printf("%sというファイルは存在します。\n", filename);
    }
    fclose(fp);
}
