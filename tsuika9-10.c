#include<stdio.h>

int lookup(const char *, char);
int main()
{
    int quantity;
    char inputString[40], findCharacter;
    printf("文字列を入力してください。----");
    scanf("%s", inputString);
    printf("検索する文字を入力して下さい。----");
    scanf("%c", &findCharacter);

    //関数に飛ばす
    quantity = lookup(inputString, findCharacter);

    printf("文字列は%d個です。", quantity);

    return 0;

}

int lookup(const char inputString[], char findCharacter)
{
    int i = 0,quantityCharacter = 0;
    //whileで'\0'になるまでくるくるまわす
    printf("%s", inputString);
    while(inputString[i] != '\n'){
        if(inputString[i] == findCharacter){
        //quantityCharacterにプラス１してあげる
                quantityCharacter++;
        printf("%c",inputString[i]);
        }
    i++;
    }
    //returnでquantityCharacterを返してあげる
    return quantityCharacter;

}
