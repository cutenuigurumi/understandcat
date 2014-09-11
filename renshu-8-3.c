#include<stdio.h>

char turnOver(const char *);
int main()
{
    //reversedString[0]には'\0'が入っているので配列だけど1からスタート。
    int k = 1;
    char inputString[40], reversedString[40];
    //文字入力
    printf("文字を入力してください。");
    scanf("%s", inputString);
    reversedString = turnOver(inputString);

    printf("%s", reversedString);
    return 0;
}
//inputStringの配列の先頭アドレスを受け取る
char turnOver(const char inputString[])
{
    char reversedString[40];
    int i = 0,j = 0;
    //何文字かを確認

    while(inputString[i] != '\0'){
        i++;
    }

    //逆向きにして、別の配列に保存
    while(i >= 0){
        reversedString[j] = inputString[i];
        printf("%c", reversedString[j]);
        j++;
        i--;
    }

    printf("\n");
    return *reversedString;
}
