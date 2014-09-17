#include<stdio.h>

void alert(int);
int main(){

    int no;

    printf("警告音を何回ならしますか？");
    scanf("%d", &no);
    if(no > 10){
        printf("10回以上はならせません。");
    } else if(no < 0) {
        printf("入力値がエラーみたいです。");
    } else {
        alert(no);
        printf("%d回ならしました。", no);
    }
    return 0;

}

void alert(int no)
{
    int i;
    for(i = 0; i < no; i++){
        printf("\a");
    }

}
