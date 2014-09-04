#include<stdio.h>


void put_stringn(const char string[], int times);
int main()
{
    int times;
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
    int i = 1;
    do{
        printf("%s", string);
        i++;
    }while(i <= times);
    printf("\n");
}
