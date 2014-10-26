#include<stdio.h>

int main()
{
    int i = 1, number = 0;

    printf("整数を入力してください。----");
    if(scanf("%d", &number) != 1){
        scanf("%*s");
    }

    while(i <= number){
        printf("%d", i % 10);
        i++;
    }
    printf("\n");

}
