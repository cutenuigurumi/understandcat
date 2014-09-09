#include<stdio.h>

int countCharacter(char *);
void turnOverCharacter(int ,char *);
int main()
{
    int countLength = 0;
    char *inputCharacter;
    //文字入力
    printf("文字を入力してください。");
    scanf("%s", inputCharacter);

    //文字のカウント処理
    countLength = countCharacter(inputCharacter);
    turnOverCharacter(countLength, inputCharacter);

    return 0;
}

int countCharacter(char *inputCharacter)
{
    int countLength = 0;
    while(inputCharacter[countLength] != '\0'){
        countLength++;
    }
        return (countLength);

}

void turnOverCharacter(int countLength, char *inputCharacter)
{
    while(countLength >= 0){
        printf("%c", inputCharacter[countLength]);
        countLength--;
    }
    printf("\n");
}
~          
