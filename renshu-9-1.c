#define STUDENTNO 3
#include<stdio.h>

struct Record {

    char name[32];
    int japanese;
    int science;
};

int main()
{

    struct Record student[STUDENTNO];
    int i, j;
    char lookForThisName[32];

    for(i = 0; i < STUDENTNO; i++) {
        printf("生徒の名前----");
        scanf("%s", student[i].name);
        printf("国語の成績----");
        scanf("%d", &student[i].japanese);
        printf("英語の成績----");
        scanf("%d", &student[i].science);
    }

    printf("探したい人の名前を入れてください。");
    scanf("%s", lookForThisName);

    printf("DMSG lookForThisName → %s\n", lookForThisName);
    for(j = 0; j < STUDENTNO; j++){
        if(lookForThisName == student[j].name){
            printf("%s, %d, %d", student[j].name, student[j].japanese, student[j].science);
        }
        printf("DMSG student[j].name → %s\n", student[j].name);
    }

}
