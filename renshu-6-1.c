#include<stdio.h>

int keisan_m(int);


int main()
{

    int hankei, menseki = 0;
    printf("半径を入力----");
    scanf("%d", &hankei);

    menseki = keisan_m(hankei);

    printf("%dの面積は%dです。", hankei,menseki);
    return 0;

}


int keisan_m(int hankei)
{
    int menseki = 0;
    menseki = hankei * hankei * 3.14;
    return menseki;
}
