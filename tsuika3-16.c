
#include<stdio.h>

int inputNumber = 0;

int main()
{
    printf("点数を入力してください：");
    scanf("%d", &inputNumber);
    if(80 <= inputNumber && 100 >= inputNumber){
        printf("評価は優です\n");
    } else if(70 <= inputNumber && 79 >= inputNumber){
        printf("評価は良です\n");
    } else if(60 <= inputNumber && 69 >= inputNumber){
        printf("評価は可です\n");
    } else {
        printf("評価は不可です\n");
    }
    return 0;
}
