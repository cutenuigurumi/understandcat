#include<stdio.h>
#include<string.h>

int write_addresslist(char *);
void lookfor_addresslist(char *);
int main()
{
    char filename[256];
    int endWrite = 0,decision = 0, errorFlag = 0;

    do{
        printf("登録…1 / 読み込み…0\n");
        if(scanf("%d", &decision) != 1){
            scanf("%*s");
        }
        if(decision == 1){
            //書き込みモード
            while(endWrite == 0){
                endWrite = write_addresslist(filename);
            }
        } else if(decision == 0){
            //読み込みモード
            lookfor_addresslist(filename);
        } else {
            printf("エラーです！");
            errorFlag = 1;
        }
    }while(errorFlag == 1);


    return 0;
}

int write_addresslist(char *filename)
{

    char name[16], address[100], tel[20];
    int decision = 0;
    char format[] = "%s %-4.1f %-4.1f\n";
    FILE *fp;
    fp = fopen("renshu-test-10-1.txt", "a");
    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
        return -1;
    }


    printf("氏名:");
    scanf("%s", name);

    printf("住所:");
    if(scanf("%s", address) != 1){
        scanf("%*s");
    }
    printf("電話番号:");
    if(scanf("%s", tel) != 1){
        scanf("%*s");
    }
    fflush( stdin );

    fprintf(fp, "%s, %s, %s\n", name, address, tel);
    printf("書き込みました。\n");

    //decisionに1か0以外が入れられたらループ
    //1なら終了、0なら続ける
    do{
        printf("終了しますか(Yes…1/ No…0):");
        if(scanf("%d", &decision) != 1){
            printf("数値以外は入力できません");
            scanf("%*s");
            continue;
        }
        if(decision == 1){
            printf("終了します\n");
            return decision;
        }else if(decision == 0){
            break;
        }else{
            printf("1と0以外は入れられません。入力ミスです\n");
            continue;
        }
    }while(decision == 0);
    return decision;
}

void lookfor_addresslist(char *filename)
{
    FILE *fp;
    fp = fopen("renshu-test-10-1.txt", "r");

    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
    }

    char c;
    while(fscanf(fp, "%c", &c) != EOF){
        printf("%c", c);
    }
}
