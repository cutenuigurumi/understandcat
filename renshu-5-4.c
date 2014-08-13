#include<stdio.h>

int main(){
    double h = 0.0, w = 0, bmi = 0, risou = 0;

    printf("体重を入力してください。(kg)\n");
    scanf("%lf", &w);
    printf("身長を入力してください。(m)\n");
    scanf("%lf", &h);

    bmi = w/(h*h);
    risou = (h * h) * 22;

    printf("あなたのBMIは%4.2fです。\n", bmi);
    printf("あなたの理想の体重は%4.2fです。\n", risou);

    return 0;
}

