#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LENGTH 10
#define MESSAGELENGTH 30
#define TXT "txt"

//拡張子を引数として渡す
char* getExtension(const char *);
int main(int argc, char *argv[])
{
    char message[LENGTH], string[LENGTH], filename[LENGTH], extension[LENGTH];
    int extensionFlag = 0, length = LENGTH;

    FILE *fp;
    //引数の数チェック
    if(argc > 2){
        fprintf(stderr, "引数が多すぎます。\n");
        exit(-1);
    }
    if(argc == 1){
        fprintf(stderr, "引数が少なすぎます\n");
        exit(-1);
    }
    if(strlen(argv[1]) >= LENGTH){
        fprintf(stderr, "ファイル名が長過ぎます\n%d文字しか入れられません", LENGTH);
        exit(-1);
    }

    strcpy(filename, argv[1]);

    //extensionに拡張子を収納
    strcpy(extension, getExtension(filename));

    //拡張子同士を比較
    if(strcmp(extension, TXT) != 0){
        fprintf(stderr, "拡張子が違います\n");
        exit(-1);
    }

    fp = fopen(filename, "a");
    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
        exit (-1);
    }

    do{
        fputs("文字列を入力してください:" , stdout);
        fgets(string, sizeof(string), stdin);
        if(string[0] == '\n'){
            fprintf(stderr, "何も入力されていません。\n");
            continue;
        }
        if (strchr(string, '\n') != NULL) {
            string[LENGTH - 1] = '\0';
        } else {
            fprintf(stderr, "文字数が多すぎます。\n%d文字以内にして下さい。\n", length);
            // 入力ストリームをクリアする処理。
            while(getchar() != '\n');
            continue;
        }
        fputs(string, fp);
        fputs("文字をファイルに書き込みました\n", stdout);
        break;
    }while(1);

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
    static char extension[LENGTH];
    int i = 0;

    for(i = strlen(filename) - 1; i >= 0; i--){
        if(filename[i] == '.'){
            break;
        }
        strcpy(extension, &filename[i]);
    }
        return extension;

}
