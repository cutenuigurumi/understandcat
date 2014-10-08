#include<stdio.h>
#include<string.h>
#define LENGTH 11

int lookup(const char *, char );
int main()
{
    int i = 0;
    //11にするのはnull文字の分。
    char string[LENGTH], userInputChar[LENGTH], oneChar;
    printf("文字列を入力してください。\n10文字以上は読み込みません。----");
    scanf("%10s%*[^\n]", string);
    printf("検索する文字を入力して下さい。----");
    scanf("%10s%*[^\n]", userInputChar);
    //エラー処理

    while(userInputChar[i] != '\0'){
        i++;
    }
    if(i != 1){
        printf("1文字しか入力ができません。\nそれ以下は切り捨てられます\n");
    }
    oneChar =  userInputChar[0];
    //関数に飛ばす
    printf("文字列は%d個です。\n", lookup(string, oneChar));

    return 0;

}

/* ----------------------------------------------------------- *
 * lookup : 文字列の中に検索する文字が何文字あるか探す。
 *   引数：String: 文字列 oneChar: 文字
 *   戻り値：文字列の中に、文字が何文字あるか。
 * ----------------------------------------------------------- */

int lookup(const char *String, char oneChar)
{
    int i = 0, stringCounter = 0;
    //whileで'\0'がくるまで
    while(String[i] != '\0'){
        if(String[i] == oneChar){
            stringCounter++;
        }
        i++;
    }
    //returnで文字数を返してあげる
    return stringCounter;

}
