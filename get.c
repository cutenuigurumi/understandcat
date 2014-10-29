#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZES 200
#define SIZEFILE 20
#define METHOD 5
#define PATH 50
#define COOKIE 20
#define TXT "txt"
#define SIZETXT 5

//拡張子を引数として渡す
char* getExtension(const char *);
int main(int argc, char *argv[])
{
    FILE *fp;
    char s[SIZES], filename[SIZEFILE], extension[SIZETXT], *bufferMethod, method[METHOD], *bufferPath, path[PATH], *bufferCookie, cookie[COOKIE];

    int i = 0, firstTimeFlag = 0,j = 0, postFlag = 0,paragrahFlag = 0, txt = SIZETXT;

    //引数の数チェック
    if(argc > 2){
        fprintf(stderr, "引数が多すぎます。\n");
        exit(-1);
    }
    if(argc == 1){
        fprintf(stderr, "引数が少なすぎます\n");
        exit(-1);
    }
    if(strlen(argv[1]) >= SIZEFILE){
        fprintf(stderr, "ファイル名が長過ぎます\n%d文字しか入れられません", SIZEFILE);
        exit(-1);
    }

    strcpy(filename, argv[1]);

    //extensionに拡張子を収納
    strcpy(extension, getExtension(filename));

    //拡張子同士を比較同じなら0を返す
    if(strcmp(extension, TXT) != 0){
        fprintf(stderr, "拡張子が違います\n");
        exit(-1);
    }

    fp = fopen(filename, "r");
    if(fp == NULL){
        fprintf(stderr, "ファイルのオープンに失敗しました。\nファイルがありません\n");
        exit (-1);
    }
    //ストリームから1行ずつ読み込み、NULLになったら終了
    while(fgets(s, sizeof(s), fp) != NULL){
        //リクエストラインの解析
        if(firstTimeFlag == 0){
            bufferMethod = strtok(s, " ");
            strcpy(method, bufferMethod);
            fprintf(stdout, "メソッドは%s\n", method);
            if(strcmp(method, "POST") == 0){
                postFlag = 1;
            }
            bufferPath = strtok(NULL, " ");
            strcpy(path, bufferPath);
            fprintf(stdout, "パスは%s\n", path);
            firstTimeFlag = 1;
        }
        if(strncmp(s, "Cookie:", 7) == 0){
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
/* ----------------------------------------------------------- *
 *   getExtension: filenameから拡張子だけを抜き出して、extension
 *   に格納する。
 *   引数：filename
 *   戻り値：なし。
 * ----------------------------------------------------------- */
char* getExtension(const char *filename)
{
    char txt[4] = TXT;
    static char extension[SIZETXT];
    int i = 0;

    for(i = strlen(filename) - 1; i >= 0; i--){
        if(filename[i] == '.'){
            break;
        }
        strcpy(extension, &filename[i]);
    }
        return extension;

}
