#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILENAME "get1.txt"
#define METHOD1 "GET"
#define METHOD2 "POST"
#define SIZES 100
#define SIZEFILE 20
#define SIZEMETHOD 5
#define SIZEPATH 30

int main()
{
    FILE *fp;
    char s[SIZES], filename[SIZEFILE], *method, *path, *mod;

    int i = 0, count = 1, k = 0;

    fp = fopen(FILENAME, "r");
    if(fp == NULL){
        fprintf(stderr, "ファイルのオープンに失敗しました。\nファイルがありません\n");
        exit (-1);
    }
    //ストリームから1行ずつ読み込み、NULLになったら終了
    while(fgets(s, sizeof(s), fp) != NULL){
        //1行目の時だけの処理：GETかPOST と パスの取得
        if(count == 1){
            method = strtok(s, " ");
            path = strtok(NULL, " ");
            mod = strtok(NULL, " ");
            fputs(path, stdout);
            if(strcmp(method, METHOD1) == 0){
                fputs("このメソッドはGETです\n", stdout);
            }
            if(strcmp(method, METHOD2) == 0){
                fputs("このメソッドはPOSTです\n", stdout);
            }
            //ここでiをプラスしないと次でスペースから始まってしまう。
        }
        count++;
    }
    fputs(path ,stdout);
    fputs("\n" ,stdout);
    fputs(s, stdout);
    fclose(fp);
    exit(0);
}
