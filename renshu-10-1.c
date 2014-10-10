#include<stdio.h>
#include<string.h>
#define FILENAME "renshu-test-10-1.txt"

int writeAddressList();
void lookforAddressList();
int isErrorString(char *);
int main()
{
    int endWrite = 0,decision = 0, errorFlag = 0;

    do{
        printf("登録…1 / 読み込み…0\n");
        if(scanf("%d", &decision) != 1){
            scanf("%*s");
        }
        if(decision == 1){
            //書き込みモード
            while(endWrite == 0){
                endWrite = writeAddressList();
            }
        } else if(decision == 0){
            //読み込みモード
            lookforAddressList();
        } else {
            printf("エラーです！");
            errorFlag = 1;
        }
    }while(errorFlag == 1);


    return 0;
}
/* ----------------------------------------------------------- *
 * writeAddressList : 氏名、住所、電話番号をファイル名に
 * 書き込んでいく。
 *   引数：なし
 *   戻り値：decision 書き込みを続ける(1)か、終了する(0)かの判断。
 * ----------------------------------------------------------- */
int writeAddressList()
{

    char name[20], address[20], tel[20];
    int decision = 0;
    FILE *fp;
    fp = fopen(FILENAME, "a");
    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
        return -1;
    }

    printf("氏名:");
    decision = isErrorString(name);
    if(decision == -1){
        printf("エラーです。\n");
    }

    printf("住所:");
    decision = isErrorString(address);

    printf("電話番号:");
    decision = isErrorString(tel);

    fprintf(fp, "%s,%s,%s\n", name, address, tel);
    printf("書き込みました。\n");

    //decisionに1か0以外が入れられたらループ
    //1なら終了、0なら続ける
    do{
        printf("終了しますか(Yes…1/ No…0):");
        if(scanf("%d", &decision) != 1){
            printf("数値以外は入力できません");
            scanf("%*s");
            continue;
        }
        if(decision == 1){
            printf("終了します\n");
            return decision;
        }
        if(decision == 0){
            break;
        }else{
            printf("1と0以外は入れられません。入力ミスです\n");
            continue;
        }
    }while(decision == 0);
    return decision;
}
/* ----------------------------------------------------------- *
 * lookforAddressList : 検索したい名前を入力すると、
 * 一致した名前、住所、電話番号を画面に出力する
 *   引数：なし
 *   戻り値：なし
 * ----------------------------------------------------------- */
void lookforAddressList()
{
    FILE *fp;
    fp = fopen(FILENAME, "r");
    char buffer[100],searchName[20], *name, *address, *tel, yesno[6];
    int no = 0;

    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
    }
    printf("検索したい名前を入れて下さい----");
    if(scanf("%s", searchName) != 1){
        scanf("%*s");
    }

    while(fgets(buffer, sizeof(buffer), fp) !=NULL){
        name = strtok(buffer, ",");
        address = strtok(NULL, ",");
        tel = strtok(NULL, ",");
        if(strstr(name, searchName) != NULL) {
        printf("名前:%-s\n住所:%-s\nTEL:%-s", name,address,tel);
        }
        printf("さらに検索を続けますか？(y/n)----");
        if(scanf("%s", yesno) != 1){
            scanf("%*s");
        }
        if(yesno[0] == 'y' || yesno[0] == 'Y'){
            continue;
        }
        if(yesno[0] =='n' || yesno[0] == 'N') {
            printf("終了します\n");
            break;
        } else {
            printf("エラーです。終了します。\n");
            break;
        }
    }
}
/* ----------------------------------------------------------- *
 * isErrorString : 引数がエラーかどうかを判断して、エラーがあれば-1
 * を返して、バッファをクリア
 *   引数: char型の変数
 *   戻り値：何も無ければ0, エラーがあれば-1
 * ----------------------------------------------------------- */

int isErrorString(char *string)
{
    if(scanf("%s", string) != 1){
        scanf("%*s");
        return -1;
    }
    return 0;
}
