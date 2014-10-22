#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LENGTH 20
#define FEXTENSION1 "txt"

int checkExtension(const char *, const char *);
int main(int argc, char *argv[])
{
    FILE *fpRead, *fpWrite;
    char c, readFilename[LENGTH], writeFilename[LENGTH];

    //引数の数チェック
    if(argc > 3){
        fprintf(stderr, "引数が多すぎます。\n");
        exit(-1);
    }
    if(argc == 2){
        fprintf(stderr, "引数が一つしかありません\n");
        exit(-1);
    }
    if(argc <= 1){
        fprintf(stderr, "引数がありません。\n");
        exit(-1);
    }
    if(strlen(argv[1]) >= LENGTH || strlen(argv[2]) >= LENGTH){
        fprintf(stderr, "ファイル名が長過ぎます！\n終了します\n");
        exit(-1);
    }

    strcpy(readFilename, argv[1]);
    strcpy(writeFilename, argv[2]);

    //.以降を見る処理に
    if(checkExtension(readFilename, writeFilename) != 0){
        fprintf(stderr, "拡張子が違います\n");
        exit(-1);
    }

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

    fputs("書き込みが完了しました。\n", stdout);

    fclose(fpRead);
    fclose(fpWrite);
    exit(0);

}

/* ----------------------------------------------------------- *
 * checkExtension: 拡張子がtxtかhtmlかをチェックする。
 *   引数：filename
 *   戻り値：0拡張子がtxtかhtmlだった。1それ以外。
 * ----------------------------------------------------------- */
int checkExtension(const char *readFilename, const char *writeFilename)
{
    char extension1[] = FEXTENSION1, bufferExtension[LENGTH];
    int i = 0;

    for(i = strlen(readFilename) - 1; i >= 0; i--){
        if(readFilename[i] == '.'){
            break;
        }
        strcpy(bufferExtension, &readFilename[i]);
    }
    for(i = strlen(writeFilename) - 1; i >= 0; i--){
        if(writeFilename[i] == '.'){
            break;
        }
        strcpy(bufferExtension, &writeFilename[i]);
    }

    //拡張子同士を比較同じなら0を返す
    if(strcmp(bufferExtension, extension1) == 0){
        return 0;
    } else {
        return 1;
    }
}
