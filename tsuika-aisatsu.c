#include<stdio.h>
int countCharacters(char *);

int main()
{
    int stringLength;
    char name[40];
    printf("お名前を40文字以内で:");
    scanf("%[^\n]", name);

    stringLength = countCharacters(name);
    if(stringLength > 40){
        printf("40文字以内で入力してください。\n");
    } else {
        printf("はじめまして、%sさん！\n", name);
    }
    return 0;
}


int countCharacters(char *name)
{
    int stringLength = 0, countEndFlag = 0;
    do{
        if(name[stringLength] == '\0'){
            countEndFlag = 1;
            return stringLength;
        }
        stringLength++;
    }while(countEndFlag == 0);
    return stringLength;
}
