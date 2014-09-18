#include<stdio.h>

int check_error(int, int);
void put_stars(int);
int main()
{
    int  i, height, width, errorFlag = 0;

    printf("長方形を作りましょう\n");
    printf("横幅----");
    if(scanf("%d", &width) !=1){
        scanf("%*s");
    }
    printf("高さ----");
    scanf("%d", &height);

    printf("%d,  %d\n", width, height);
    errorFlag = check_error(width, height);
    if(errorFlag != 1){
        for(i = 1; i <= height; i++){
            put_stars(width);
        }
    }
}

void put_stars(int no)
{
    int i;
    for(i = 1; i <= no; i++){
        printf("*");
    }
    printf("\n");
}

int check_error(int width, int height)
{
    int errorFlag = 0;
    if(width > 1000 || height > 1000 || width <= 0|| height <= 0){
        printf("入力値がエラーみたいです。\n");
        errorFlag = 1;
    }
    if(width > 10 || height > 10){
        printf("10以上は入力できません。\n");
        errorFlag = 1;
    }
    return errorFlag;
}
