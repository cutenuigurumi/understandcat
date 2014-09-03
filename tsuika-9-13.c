#include<stdio.h>


void put_stringn(const char string[], int times);
int main()
{
    int times, count_Length_Func;
    char string[40];
    printf("文字列を入力してください：");
    scanf("%s", string);
    printf("何回表示しますか：");
    scanf("%d", &times);

        put_stringn(string, times);
    return 0;
}

void put_stringn(const char *string, int times)
{
    int i = 0;
    do{
        printf("%s", string);
        i++;
    }while(times > i);
}

