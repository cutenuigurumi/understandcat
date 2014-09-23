#define STUDENTNO 3
#include<stdio.h>
#include<string.h>

struct Record {

    char name[32];
    int japanese;
    int science;
};
void lookfor(struct Record *, char *);

int main()
{
    int i = 0;
    char lookForThisName[32];
    struct Record student[STUDENTNO];

    while(i < STUDENTNO) {
        printf("生徒の名前----");
        if(scanf("%s", student[i].name) != 1){
            scanf("%*s");
            continue;
        }
        printf("国語の成績----");
        if(scanf("%d", &student[i].japanese) != 1){
            scanf("%*s");
            continue;
        }
        is_check(student[i].japanese);
        printf("理科の成績----");
        if(scanf("%d", &student[i].science) != 1){
            scanf("%*s");
            continue;
        }
        is_check(student[i].science);
    i++;
    }
    printf("探したい人の名前を入れてください。");
    scanf("%s", lookForThisName);

    lookfor(student, lookForThisName);

}

void lookfor(struct Record *student, char *lookForThisName)
{
    int i, j, k, studentNameLength;

    //i 生徒の人数
    for(i = 0; i < STUDENTNO; i++){
        //j 文字を指定
        studentNameLength = strlen(student[i].name);
        //k studentNameLengthの文字数
        for(k = 0; k < studentNameLength; k++){
            if(lookForThisName[k] == student[i].name[k]){
                printf("氏名:%s, 国語:%d点, 英語:%d点\n", student[i].name, student[i].japanese, student[i].science);
                break;
            }
        }
    }
}

void is_check(*score)
{

    if(score > 100 | score < 0){
        printf("入力値がエラーみたいです。。\n");
    }
}
