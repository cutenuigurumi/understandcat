#include<stdio.h>

void put_stringn(const char string[], int times);
int count_length_func(const char string[]);
int main()
{
    int times, count;
    char string[40];
    printf("文字列を入力してください：");
    scanf("%40[^\n]", string);
    count = count_length_func(string);
    if(count > 40){
        printf("40文字以上は入力ができません\n");
    } else {
        printf("何回表示しますか：");
        scanf("%d", &times);
        if(times < 99){
            put_stringn(string, times);
        } else {
            printf("99回以上は入力できませんよ。\nもしくは値が不正っぽいですよ。\n");
        }
    }
    return 0;
}

void put_stringn(const char *string, int times)
{
    int i = 1;
    while(times >= i){
        printf("%s", string);
        i++;
    }
    printf("\n");
}

int count_length_func(const char *string)
{
//変数用意
    int endFlag = 0,i = 0,count = 1;

    //\フラッグがたつまで繰り返すはじめ
    do {
        //string[i]の中身は\0?
        if(string[i] != '\0'){
            count++;
        } else {
            //noだったらフラッグを立てる
            endFlag = 1;
        }
        i++;
    //フラッグがたつ迄繰り返す終わり
    } while(endFlag == 0);

    return count;
}
