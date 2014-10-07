#include<stdio.h>

int main()
{
    int i = 0,countUpNumber = 1, inputNumber = 0;

    printf("整数を入力してください。----");
    if(scanf("%d", &inputNumber) != 1){
        scanf("%*s");
    }
    //countUpNumberは1~9まで9になったら0をいれて1からスタート
    //なのでiとは別の変数を使用
    while(i < inputNumber){
        printf("%d", countUpNumber);
        if(countUpNumber == 9){
            countUpNumber = 0;
        }else{
            countUpNumber++;
        }
        i++;
    }
    printf("\n");
}
