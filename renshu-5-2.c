#include<stdio.h>


int main()
{
    int i = 100, sum = 0;
    while (i > 0){
        sum = sum + i;
        i--;
    }
    printf("1+2+3+...100の答えは%dです。/n", sum);
    return 0;
}
