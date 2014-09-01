#include<stdio.h>


int main()
{

    char name[40];
    int i, overFourtyFlag = 0;

    printf("お名前を40文字以内で:");
    scanf("%[^\n]", name);

    while(name[i] != '\0') {
        if(i > 40) {
            printf("40文字以内で入力してください\n");
            overFourtyFlag = 1;
            break;
        }
    i++;
    }
    if(overFourtyFlag == 0){
        printf("はじめまして、%sさん！\n", name);
    }

    return 0;

}
