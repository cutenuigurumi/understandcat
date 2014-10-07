#include<stdio.h>

int main()
{
    int inputStep = 0,no = 1, i = 0, j = 0, errorFlag = 0;
    printf("ピラミッドを造りましょう。\n");
    do{
        printf("何段ですか？:");
        if(scanf("%d", &inputStep) != 1){
            scanf("%*s");
            printf("数値が不正です。戻ります。\n");
            errorFlag = 1;
        } else {
            errorFlag = 0;
        }
    }while(errorFlag == 1);

    //noが*の個数
    while(inputStep > i){
        for(j = 0; no > j; j++){
            printf("*");
        }
        no = no + 2;
        i++;
        printf("\n");
    }
}
