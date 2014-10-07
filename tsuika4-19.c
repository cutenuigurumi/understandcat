#include<stdio.h>
int main()
{
    int i = 1;
    while(i <= 50){
        //5で割り切れるなら改行
        if(i % 5 == 0){
            printf("%2d\n", i);
        //割り切れなければ後ろに数字が続くのでスペース
        } else {
            printf("%2d ", i);
        }
        i++;
    }
}
