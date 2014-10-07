#include<stdio.h>

int main() {

    int i = 2, inputNumber = 0, errorFlag = 0;

    do{
        printf("整数を入力してください:");
        if(scanf("%d", &inputNumber) != 1){
            scanf("%*s");
            printf("エラー！正しい数値を入力してください。\n");
            errorFlag = 1;
        }else{
            errorFlag = 0;
        }
    }while(errorFlag == 1);

    while(i <= inputNumber){
        printf("%d ", i);
        i = i + 2;
    }
    printf("\n");
}
