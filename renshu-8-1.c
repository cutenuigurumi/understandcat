#include<stdio.h>

int main()
{
    int i = 0, studentNumber = 0;
    double tmpStudentRecord = 0,studentRecord[40],average = 0, sum = 0;

    do {
        printf("出席番号%d番の100mのタイムを入力してください(終了→ 999)----", i + 1);
        if(scanf("%lf", &tmpStudentRecord) != 1){
            scanf("%*s");
            printf("値が不正です\n");
            continue;
        }
        if(tmpStudentRecord == 999){
            break;
        }
        if(tmpStudentRecord > 100 || tmpStudentRecord <= 0){
            printf("100秒以上、または値が不正です。\n登録できません。\n");
            continue;
        }
        studentRecord[i] = tmpStudentRecord;
        sum += tmpStudentRecord;
        i++;
    }while(i < 40);

    if(i != 0){
        average = sum / i;
    }

    printf("%d名の100m走の平均タイムは%5.2fです。\n", i, average);

    while(studentNumber < i){
        printf("出席番号%d:%5.2f秒です。\n", studentNumber +1, studentRecord[studentNumber]);
        studentNumber++;
    }

    return 0;


}
~             
