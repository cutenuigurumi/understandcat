#include<stdio.h>
#define TIMES 50

int main()
{
    int i = 1;
    char endChar[2];
    while(i <= TIMES){
        if(i % 5 == 0){
            *endChar = '\n';
        } else {
            *endChar = ' ';
        }
        printf("%2d%s",i, endChar);
        i++;
    }
}
