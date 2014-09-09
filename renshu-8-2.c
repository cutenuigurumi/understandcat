#include<stdio.h>

int main()
{
    int day = 0, inputDate = 0, endFlag = 0;
    char *charDay[] = {"土","日","月","火","水","木","金"};

    do{
        printf("日付を入力して下さい。----");
        if(scanf("%d", &inputDate) != 1){
            scanf("%*s");
            printf("値が不正です。\n");
            continue;
        }
        //31より大きかったり、マイナスだったらエラー
        if(inputDate > 31 || inputDate <= 0){
            printf("正しい日付を入力してください。\n");
            continue;
        }
            day = inputDate % 7;
            printf("%s曜日です\n", charDay[day]);
            endFlag = 1;
    } while(endFlag == 0);

}
