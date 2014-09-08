#include<stdio.h>

int main()
{
    int day = 0, inputDate = 0;

    printf("日付を入力して下さい。----");
    scanf("%d", &inputDate);

    //31より大きかったり、マイナスだったらエラー
    if(inputDate > 31 || inputDate <= 0){
        printf("正しい日付を入力してください。");
        day = 999;
    } else {
        day = inputDate % 7;
    }
    //1〜7だったらそのまま通す
    switch(day){
        case 1:
            printf("日曜日です。\n");
            break;
        case 2:
            printf("月曜日です。\n");
            break;
        case 3:
            printf("火曜日です。\n");
            break;
        case 4:
            printf("水曜日です。\n");
            break;
        case 5:
            printf("木曜日です。\n");
            break;
        case 6:
            printf("金曜日です。\n");
            break;
        case 0:
            printf("土曜日です。\n");
            break;
        default:
            printf("エラーです。\n");
    }
}
