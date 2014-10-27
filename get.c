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
    //*methodを使用するのは、strtok関数が、区切った文字列へのポインタを返す変数のため。method[METHOD]は動かない。
    char s[SIZES], filename[SIZEFILE], *bufferMethod, method[5], *bufferPath, path[PATH], *bufferCookie, cookie[COOKIE];

    int i = 0, count = 1,j = 0;

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
            if(strcmp(method, METHOD1) == 0){
                fputs("このメソッドはGETです\n", stdout);
            }
            if(strcmp(method, METHOD2) == 0){
                fputs("このメソッドはPOSTです\n", stdout);
            }
            //ここでiをプラスしないと次でスペースから始まってしまう。
        }
        if(count == 8){
            bufferCookie = strtok(s, ":");
            bufferCookie = strtok(NULL, "\n");
            strcpy(cookie, bufferCookie);
        }
        count++;
    }
    fprintf(stdout, "パスは%s\n", path);
    fprintf(stdout, "クッキーの値は%s\n", cookie);
    fclose(fp);
    exit(0);
}

