#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILENAME "get1.txt"
#define METHOD1 "GET"
#define METHOD2 "POST"
#define SIZES 100
#define SIZEFILE 20
#define METHOD 5
#define PATH 50
#define COOKIE 20

int main()
{
    FILE *fp;
    //配列を使用せず、ポインタを使用するのはstrtok関数が、区切った文字列へのポインタを返す変数のため。
    char s[SIZES], filename[SIZEFILE], *bufferMethod, method[METHOD], *bufferPath, path[PATH], *bufferCookie, cookie[COOKIE];

    int i = 0, count = 1,j = 0, ret = 0;

    fp = fopen(FILENAME, "r");
    if(fp == NULL){
        fprintf(stderr, "ファイルのオープンに失敗しました。\nファイルがありません\n");
        exit (-1);
    }
    //ストリームから1行ずつ読み込み、NULLになったら終了
    while(fgets(s, sizeof(s), fp) != NULL){
        //1行目の時だけの処理：GETかPOST と パスの取得
        if(count == 1){
            bufferMethod = strtok(s, " ");
            strcpy(method, bufferMethod);
            bufferPath = strtok(NULL, " ");
            strcpy(path, bufferPath);
        }
        ret = strncmp(s, "Cookie:", 7);
        if(ret == 0){
            bufferCookie = strtok(s, ":");
            bufferCookie = strtok(NULL, "\n");
            strcpy(cookie, bufferCookie);
        }
        count++;
    }
    fprintf(stdout, "メソッドは%s\n", method);
    fprintf(stdout, "パスは%s\n", path);
    fprintf(stdout, "クッキーの値は%s\n", cookie);
    fclose(fp);
    exit(0);
}
