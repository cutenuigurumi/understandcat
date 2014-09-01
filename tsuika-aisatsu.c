#include<stdio.h>

char name[40];
int i, flag = 0;

int main()
{

    printf("お名前を40文字以内で:");
    scanf("%s", name);

    while(name[i] != '\0') {
        if(i > 40) {
            printf("40文字以内で入力してください\n");
            flag = 1;
            break;
        }
    i++;
    }
    if(flag == 0){
    printf("はじめまして、%sさん！\n", name);
    }

    return 0;

}

