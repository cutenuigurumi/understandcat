#include<stdio.h>

int main()
{
    int day = 0, inputDate = 0;
    char *charDay[] = {"土","日","月","火","水","木","金"};

    printf("日付を入力して下さい。----");
    scanf("%d", &inputDate);

    //31より大きかったり、マイナスだったらエラー
    if(inputDate > 31 || inputDate <= 0){
        printf("正しい日付を入力してください。\n");
    } else {
        day = inputDate % 7;
        printf("%s曜日です\n", charDay[day]);
    }
}
