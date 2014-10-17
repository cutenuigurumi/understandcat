#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LENGTH 10
#define MESSAGELENGTH 30
#define FEXTENSION1 "txt"
#define FEXTENSION2 "html"

int checkExtension(const char *);
int main(int argc, char *argv[])
{
    char extension[LENGTH], message[LENGTH], string[LENGTH], filename[LENGTH];
    int extensionFlag = 0;

    FILE *fp;
    //引数の数チェック
    if(argc > 2){
        fprintf(stderr, "引数が多すぎます。\n");
        exit(-1);
    }
    if(argc == 1){
        fprintf(stderr, "引数がありません\n");
        exit(-1);
    }
    strcpy(filename, argv[1]);

    //.以降を見る処理に
    if(checkExtension(filename) != 0){
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
            fprintf(stderr, "文字数が多すぎます。\n");
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
 * checkExtension: 拡張子がtxtかhtmlかをチェックする。
 *   引数：filename
 *   戻り値：0拡張子がtxtかhtmlだった。1それ以外。
 * ----------------------------------------------------------- */
int checkExtension(const char *filename)
{
    char extension1[] = FEXTENSION1, extension2[] = FEXTENSION2, *bufferExtension,  buffer[LENGTH];

    strcpy(buffer, filename);

    //拡張子以下を切り取る
    bufferExtension = strtok(buffer, ".");
    bufferExtension = strtok(NULL, ".");

    //拡張子同士を比較同じなら0を返す

    if(strcmp(bufferExtension, extension1) == 0){
        return 0;
    }
    if(strcmp(bufferExtension, extension2) == 0){
        return 0;
    } else {
        return 1;
    }
}
