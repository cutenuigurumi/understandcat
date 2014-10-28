#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILENAME "POST.txt"
#define SIZES 200
#define SIZEFILE 20
#define METHOD 5
#define PATH 50
#define COOKIE 20

int main()
{
    FILE *fp;
    //配列を使用せず、ポインタを使用するのはstrtok関数が、区切った文字列へのポインタを返す変数のため。
    char s[SIZES], filename[SIZEFILE], *bufferMethod, method[METHOD], *bufferPath, path[PATH], *bufferCookie, cookie[COOKIE];

    int i = 0, firstTime = 0,j = 0, ret = 0, postFlag = 0,paragrahFlag = 0;

    fp = fopen(FILENAME, "r");
    if(fp == NULL){
        fprintf(stderr, "ファイルのオープンに失敗しました。\nファイルがありません\n");
        exit (-1);
    }
    //ストリームから1行ずつ読み込み、NULLになったら終了
    while(fgets(s, sizeof(s), fp) != NULL){
        //リクエストラインの解析
        if(firstTime == 0){
            bufferMethod = strtok(s, " ");
            strcpy(method, bufferMethod);
            fprintf(stdout, "メソッドは%s\n", method);
            if(strcmp(method, "POST") == 0){
                postFlag = 1;
            }
            bufferPath = strtok(NULL, " ");
            strcpy(path, bufferPath);
            fprintf(stdout, "パスは%s\n", path);
            firstTime = 1;
        }
        ret = strncmp(s, "Cookie:", 7);
        if(ret == 0){
            bufferCookie = strtok(s, ":");
            bufferCookie = strtok(NULL, "\n");
            strcpy(cookie, bufferCookie);
            fprintf(stdout, "クッキーの値は%s\n", cookie);
        }
        if(strcmp(s, "\n") == 0){
            paragrahFlag = 1;
            fputs("メッセージボディ\n" , stdout);
            continue;
        }
        if(paragrahFlag == 1 && postFlag == 1){
            fputs(s ,stdout);
        }
    }
    fclose(fp); 
    exit(0);
}
    
