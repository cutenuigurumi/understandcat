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
    return 0;
}
//inputStringの配列の先頭アドレスを受け取る
char* turnOver(char* inputString)
{
    char tmpString;
    int i = 0,j = 0;
    //何文字かを確認

    while(inputString[i] != '\0'){
        i++;
    }
    //最後にぬるが入ってるので、マイナス１

    printf("%d", i);
    //逆向きにして、別の配列に保存
    while(i > j){
        tmpString = inputString[i];
        inputString[i] = inputString[j];
        inputString[j] = tmpString;
        j++;
        i--;
//      printf("くるくるー\n");
    }
    int k = 0;
    while(k < j){
    printf("%c", inputString[k]);
    k++;
    }
    inputString[j] = '\0';
    printf("%s", inputString);

    printf("\n");
    return inputString;
}
