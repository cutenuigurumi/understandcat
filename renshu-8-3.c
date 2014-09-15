#include<stdio.h>
#include<string.h>

char* turnOver(char *);
int main()
{
    //reversedString[0]には'\0'が入っているので配列だけど1からスタート。
    char inputString[40], reversedString[40];
    //文字入力
    printf("文字を入力してください。");
    scanf("%s", inputString);

    printf("%s", turnOver(inputString));
    printf("\n");
    return 0;
}
//inputStringの配列の先頭アドレスを受け取る
char* turnOver(char* inputString)
{
    char reversedString[40];
    int i = 0,j = 0, n = 0;

    //何文字かを確認
    while(inputString[i] != '\0'){
        i++;
    }
    //配列は0からはじまるのでマイナス１してあげる。
    i = i - 1;
    n = i;
    //逆向きにして、別の配列に保存
    while(j <= n){
        reversedString[j] = inputString[i];
        i--;
        j++;
    }
    reversedString[j] = '\0';
    strcpy(inputString, reversedString);
    return inputString;
}
