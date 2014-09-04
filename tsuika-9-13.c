#include<stdio.h>

void put_stringn(const char string[], int times);
int count_Length_Func(const char string[]);
int main()
{
    int times, count;
    char string[40], buffer;
    printf("文字列を入力してください：");
    scanf("%40[^\n]", string);
    count = count_Length_Func(string);
    if(count > 40){
        printf("40文字以上は入力ができません\n");
    } else {
        printf("何回表示しますか：");
        scanf("%d", &times);
    }
    return 0;
}

void put_stringn(const char *string, int times)
{
    int i = 1;
    do{
        printf("%s", string);
        i++;
    }while(i <= times);
    printf("\n");
}

int count_Length_Func(const char *string)
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
