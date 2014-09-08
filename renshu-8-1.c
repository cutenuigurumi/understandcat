#include<stdio.h>

int main()
{
    int i = 0, studentNumber = 0;
    double tmpStudentRecord,studentRecord[40],average = 0, sum = 0;

    do {
        printf("出席番号%d番の100mのタイムを入力してください(終了→ 999)----", i + 1);
        scanf("%lf", &tmpStudentRecord);
        if(tmpStudentRecord == 999){
            break;
        } else if(tmpStudentRecord > 100 || tmpStudentRecord <= 0){
            printf("100秒以上、または値が不正です。\n登録できません。\n");
        } else {
            studentRecord[i] = tmpStudentRecord;
            sum += tmpStudentRecord;
            i++;
        }
    }while(i < 40);

    average = sum / i;

    printf("%d名の100m走の平均タイムは%5.2fです。\n", i, average);

    while(studentNumber < i){
        printf("出席番号%d:%5.2f秒です。\n", studentNumber +1, studentRecord[studentNumber]);
        studentNumber++;
        }

    return 0;


}
