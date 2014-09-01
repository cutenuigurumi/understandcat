#include<stdio.h>

int main()
{

    int month;

    printf("何月ですか：");
    scanf("%d", &month);

    if(month == 3 || month == 4 || month == 5){
        printf("春です。\n");
    } else if(month == 6 || month == 7 || month == 8){
        printf("夏です。\n");
    } else if(month == 9 || month == 10 || month == 11){
        printf("秋です。\n");
    } else if(month == 12 || month == 1 || month == 2){
        printf("冬です。\n");
    } else {
        printf("入力をお間違えではないですか\n");
    }

    return 0;
}
