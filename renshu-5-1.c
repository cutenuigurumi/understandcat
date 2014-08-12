#include<stdio.h>


int main()
{
    int i, sum = 0;
    for (i =1; i <= 100; i++){
        sum = sum + i;
    }
    printf("1+2+3+...100の答えは%dです。", sum);
    return 0;
}
