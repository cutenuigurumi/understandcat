#include<stdio.h>

int main()
{
    int i = 0, studentNumber[40],tmpStudentNumber, countStudent = 1;

    double studentRecord[40],average, sum;

    do{
        printf("出席番号を入力してください(999)で終了");
        scanf("%d", &tmpStudentNumber);
        if(tmpStudentNumber == 999){
            break;
        }
        studentNumber[i] = tmpStudentNumber;

        printf("100mのタイムを入力してください----");
        scanf("%lf", &studentRecord[i]);
        sum += studentRecord[i];
        countStudent++;
        i++;
    }while(i < 40);

    average = sum / i;

    printf("%d名の100m走の平均タイムは%fです。\n", i, average);
    


    return 0;


}
