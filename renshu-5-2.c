#include<stdio.h>


int main()
{
    int i = 1, sum = 0;
    do {
        sum = sum + i;
        i++;
    } while (i <= 100);
    printf("1+2+3+...100 = %dです。\n", sum);
    return 0;
}
