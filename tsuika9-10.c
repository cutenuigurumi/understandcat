#include<stdio.h>

int lookup(const char *, char *);
int main()
{
    int quantity;
    char inputString[128], findCharacter;
    printf("文字列を入力してください。----");
    scanf("%s", inputString);
    printf("検索する文字を入力して下さい。----");
    scanf(" %c",&findCharacter);


    //関数に飛ばす
    printf("文字列は%d個です。\n", lookup(inputString, &findCharacter));

    return 0;

}

int lookup(const char *inputString, char *findCharacter)
{
    int i = 0, countString = 0;
    //whileで'\0'になるまでくるくるまわす
    while(inputString[i] != '\0'){
        if(inputString[i] == *findCharacter){
            countString++;
        }
        i++;
    }
    //returnで文字数を返してあげる
    return countString;

}
