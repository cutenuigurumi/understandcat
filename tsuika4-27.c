#include<stdio.h>
#include<string.h>
#define STRINGLENGTH 120

void printPyramid(int);
int main()
{
    int inputStep = 0, errorFlag = 0;
    printf("ピラミッドを造りましょう。\n");
    do{
        printf("何段ですか？:");
        if(scanf("%d", &inputStep) != 1){
            scanf("%*s");
            printf("数値が不正です。戻ります。\n");
            errorFlag = 1;
            continue;
        }
        if(inputStep > 50){
            printf("50段以上は入力できません。\n");
            errorFlag = 1;
            continue;
        }
        errorFlag = 0;
    }while(errorFlag == 1);
    printPyramid(inputStep);
    return 0;
}

/* ----------------------------------------------------------- *
 * printPyramid : ピラミッドを*で描写します。
 *   引数：Step：ピラミッドの段数
 *   戻り値：無し
 * ----------------------------------------------------------- */
void printPyramid(int step)
{
    int i = 0, j = 0, k = 0, no = 1, space = 0;
    char string[STRINGLENGTH];
    /*space スペースを埋める数, k あと何個スペースで埋めるか
    *stepは30行目のwhile文で使っているので変えない。 */
    space = step;
    while(i < step){
        //stringは1行単位なので、ここで初期化しないといけない。
        memset(string, '\0', STRINGLENGTH);
        for(k = space;0 < k; k--){
            strcat(string, " ");
        }
        //noが*の数
        for(j = 0; no > j; j++){
            strcat(string, "*");
        }
        no = no + 2;
        i++;
        space--;
        printf("%s\n", string);
    }
}
