#include<stdio.h>
#include<string.h>

int write_profile(FILE *);

int main()
{
    FILE *fp;
    char filename[256];
    int endWrite = 0;

    fp = fopen("renshu-13-4.txt", "a");
    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
        return -1;
    }
    //終了なら1,続けるなら0が帰ってくる
    while(endWrite == 0){
        endWrite = write_profile(fp);
    }
    fclose(fp);
    return 0;
}

int write_profile(FILE *f)
{
    char name[16];
    int decision = 0;
    double weight = 0,height = 0;
    char *format = "%s %-4.1f %-4.1f\n";

    fflush( stdin );
    printf("名前:");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) -1] = '\0';

    printf("身長:");
    if(scanf("%lf", &height) != 1){
        scanf("%*s");
    }
    printf("体重:");
    if(scanf("%lf", &weight) != 1){
        scanf("%*s");
    }
    fflush( stdin );

    fprintf(f, format, name, height, weight);
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
            return decision;
        }else{
            printf("1と0以外は入れられません。入力ミスです\n");
        }
    }while(decision == 0);

    return 0;

}
