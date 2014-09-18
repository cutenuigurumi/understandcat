#include<stdio.h>

void alert(int);
int main(){

    int no;

    printf("警告音を何回ならしますか？");
    scanf("%d", &no);
    if(no < 0 || no > 1000) {
        printf("入力値がエラーみたいです。\n");
    } else if(no > 10){
        printf("10回以上はならせません。\n");
    } else {
        alert(no);
        printf("%d回ならしました。\n", no);
    }
    return 0;

}

void alert(int no)
{
    int i;
    for(i = 1; i <= no; i++){
        printf("\a");
    }

}
