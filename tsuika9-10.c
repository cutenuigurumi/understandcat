#include<stdio.h>
#include<string.h>

int lookup(const char *, char *);
int main()
{
    int quantity,i = 0;
    //41にするのはnull文字の分。
    char inputString[10], inputFindCharacter[10], findOneCharacter;
    printf("文字列を入力してください。\n10文字以上は読み込みません。----");
    scanf("%9s%*[^\n]", inputString);
    printf("検索する文字を入力して下さい。----");
    scanf("%9s%*[^\n]", inputFindCharacter);
    //エラー処理

    while(inputFindCharacter[i] != '\0'){
        i++;
    }
    if(i != 1){
        printf("1文字しか入力ができません。\nそれ以下は切り捨てられます\n");
    }
    findOneCharacter =  inputFindCharacter[0];
    //関数に飛ばす
    printf("文字列は%d個です。\n", lookup(inputString, &findOneCharacter));

    return 0;

}

int lookup(const char *inputString, char *findCharacter)
{
    int i = 0, countString = 0;
    //whileで'\0'がくるまで
    while(inputString[i] != '\0'){
        if(inputString[i] == *findCharacter){
            countString++;
        }
        i++;
    }
    //returnで文字数を返してあげる
    return countString;

}
