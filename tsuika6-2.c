#include<stdio.h>

int min3 (int, int, int);
int main(){

    int x, y, z, min;

    printf("最初の数値を入力してください。----");
    scanf("%d", &x);
    printf("二番目の数値を入力してください。----");
    scanf("%d", &y);
    printf("最後の数値を入力してください。----");
    scanf("%d", &z);

    min = min3(x, y, z);
    printf("最小値は%dです。", min);

}

int min3(int x, int y, int z){

    int min = x;

    if(y < min){
        min = y;
    }
    if(z < min){
        min = z;
    }

    return min;

}
