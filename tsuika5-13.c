#define STUDENTNO 5

#include<stdio.h>
#include<stdbool.h>

int check_weight(double);
int main()
{
    int i = 0, errorFlag = 0;
    double  max,min,weight[5];

    while(i < STUDENTNO){
        printf("%d人目の体重を入力して下さい:", i + 1);
        if(scanf("%lf", &weight[i]) != 1){
            scanf("%*s");
            printf("入力値がエラーみたいです。。\n");
            continue;
        }
        errorFlag = check_weight(weight[i]);
        if(errorFlag  == 1){
            continue;
        }
        i++;
    }

    for(i = 0; i < STUDENTNO; i++){
        if(i == 0){
            max = weight[i];
            min = weight[i];
        }
        if(max < weight[i]){
            max = weight[i];
        }
        if(min > weight[i]){
            min = weight[i];
        }
    }

    printf("最も重い人の体重:%5.2f\n", max);
    printf("最も軽い人の体重:%5.2f\n", min);

}
/* ----------------------------------------------------------- *
 * is_error : 入力された体重が200を越えていたり0以下だったら
 * 戻り値でエラー、エラーメッセージを出力する。
 *   引数：weight 体重
 *   戻り値：errorFlag エラーだったら1,そうでなければ0を返す
 * ----------------------------------------------------------- */

int check_weight(double weight)
{
    int errorFlag = 0;
    if(weight > 200 | weight < 0){
        printf("200以上、0以下の数値は入力できません\n");
        errorFlag = 1;
    }
    return errorFlag;
}
