include<stdio.h>

double inputScore;
int i = 0, resultScore;

int main()
{
    printf("点数を入力してください(小数点以下は切り捨てされます)：");
    scanf("%lf", &inputScore);
    resultScore = (int)inputScore;

    printf("%d", resultScore);

    if(resultScore > 100) {
        printf("数字を間違えていませんか\n");
    } else if(resultScore >= 80 &&resultScore <= 100){
        printf("評価は優です\n");
    } else if(resultScore >= 70 && resultScore <= 79){
        printf("評価は良です\n");
    } else if(resultScore >= 60 && resultScore <= 69){
        printf("評価は可です\n");
    } else {
        printf("評価は不可です\n");
    }

    return 0;
}
