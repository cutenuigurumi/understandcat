
#define STUDENTNO 3
#include<stdio.h>
#include<string.h>

struct Record {

    char name[5];
    int japanese;
    int science;
};
void lookfor(struct Record *, char *);

int main()
{
    int i = 0;
    char lookForThisName;
    struct Record student[STUDENTNO];

    while(i < STUDENTNO) {
        printf("%d番目の生徒の名前----", i + 1);
        if(scanf("%s", student[i].name) != 1){
            scanf("%*s");
            printf("不正な値です。\n");
            continue;
        }
        printf("%d番目の国語の成績----", i + 1);
        if(scanf("%d", &student[i].japanese) != 1){
            scanf("%*s");
            printf("エラーです。名前の入力に戻ります\n");
            continue;
        }
        printf("%d番目の理科の成績----", i + 1);
        if(scanf("%d", &student[i].science) != 1){
            scanf("%*s");
            printf("エラーです。名前の入力に戻ります\n");
            continue;
        }
        i++;
    }
    printf("探したい人の名前を一文字入れてください。");
    if(scanf("%s", &lookForThisName) != 1){
        scanf("%*s");
        printf("エラーです。最初の一文字だけ検索します。\n");
    }

    lookfor(student, &lookForThisName);

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
            if(*lookForThisName == student[i].name[k]){
                printf("氏名:%s, 国語:%d点, 英語:%d点\n", student[i].name, student[i].japanese, student[i].science);
                break;
            }
        }
    }
}
