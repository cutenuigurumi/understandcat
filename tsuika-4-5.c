#include<stdio.h>

int inputNumber1 = 0, inputNumber2 = 0, low = 0, high = 0, check = 0, total = 0;

int main()
{
    while(inputNumber1 == inputNumber2){
        printf("二つの整数を入力してください。\n");
        printf("整数1:");
        scanf("%d", &inputNumber1);

        printf("数値2:");
        scanf("%d", &inputNumber2);

        if(inputNumber1 == inputNumber2){
            printf("同じ数値は入れられません\n");
        }
    }
    if (inputNumber1 > inputNumber2){
        high = inputNumber1;
        low = inputNumber2;
    } else {
        high = inputNumber2;
        low = inputNumber1;
    }

    check = low;
    while(check <= high){
        total += check;
        check++;
    }
    printf("%d以上%d以下の数値の和は%dです。\n", low, high, total);
    return 0;
}
