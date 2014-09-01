#include<stdio.h>
#include<stdlib.h>

int inputNumber;
int i = 0, flag;
char charNumber[100];

int main()
{
    do {
        printf("点数を入力してください：");
        scanf("%d", &inputNumber);
        sprintf(charNumber, "%d", inputNumber);

        printf("ナンバー：%s,%d", charNumber,inputNumber );
        while(charNumber[i] != '\0') {
            if(charNumber[i] == '.'){
                printf("小数点以下は入れないでください\n");
                break;
            }
            i++;
        }
    } while(1);

    if(inputNumber > 100) {
        printf("数字を間違えていませんか\n");
    } else if(inputNumber >= 80 &&inputNumber <= 100){
        printf("評価は優です\n");
    } else if(inputNumber >= 70 && inputNumber <= 79){
        printf("評価は良です\n");
    } else if(inputNumber >= 60 && inputNumber <= 69){
        printf("評価は可です\n");
    } else {
        printf("評価は不可です\n");
    }

    return 0;
}
