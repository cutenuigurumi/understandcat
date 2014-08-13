#include<stdio.h>

int main()
{
    int sum = 0, p = 0, n = 0, max = 0, min = 100;

    while(p != -1){
        printf("点数(-1で終了)----");
        scanf("%d", &p);
        if(p != -1) {
            if(max < p){
                max = p;
            }
            if(min > p){
                min = p;
            }
            sum = sum + p;
            n++;
        }
    }
    if(n != 0) {
        printf("全部の受験者数は%d人です。\n", n);
        printf("最高点:%d,最低点%d,平均点:%5.1f\n", max, min, (double)sum /n);
    }
    return 0;
}
