#include<stdio.h>
int main()
{
    int i = 1;
    while(i <= 50){
        if(i % 5 == 0){
            printf("%2d\n", i);
        } else {
            printf("%2d ", i);
        }
        i++;
    }
}
