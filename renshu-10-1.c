#include<stdio.h>
#include<string.h>
#define FILENAME "renshu-test-10-1.txt"
#define LENGTH 10

int writeAddressList();
void lookforAddressList();
void clearBuffer();
int main()
{
    int endWrite = 0,decision = 0, errorFlag = 0;

    do{
        printf("登録…1 / 読み込み…0\n");
        if(scanf("%d", &decision) != 1){
            clearBuffer();
            errorFlag = 1;
            continue;
        }
        if(decision == 1){
            //書き込みモード
            while(endWrite == 0){
                endWrite = writeAddressList();
            }
            break;
        } else if(decision == 0){
            //読み込みモード
            lookforAddressList();
            break;
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
 *   戻り値：decisionFlag 書き込みを続ける(1)か、終了する(0)かの判断。
 * ----------------------------------------------------------- */
int writeAddressList()
{

    char name[LENGTH], address[LENGTH], tel[LENGTH];
    int decisionFlag = 0;
    FILE *fp;
    fp = fopen(FILENAME, "a");
    if(fp == NULL){
        perror("ファイルのオープンに失敗しました。\n");
        return -1;
    }

    printf("氏名:");
    scanf("%9s%*[^\n]", name);

    printf("住所:");
    scanf("%9s%*[^\n]", address);

    printf("電話番号:");
    scanf("%9s%*[^\n]", tel);

    fprintf(fp, "%s,%s,%s\n", name, address, tel);
    printf("書き込みました。\n");

    /*decisionFlagに1か0以外が入れられたらループ
    *1なら終了、0なら続ける*/
    do{
        printf("終了しますか(Yes…1/ No…0):");
        if(scanf("%d", &decisionFlag) != 1){
            printf("数値以外は入力できません");
            clearBuffer();
            continue;
        }
        if(decisionFlag == 1){
            printf("終了します\n");
            return decisionFlag;
        }
        if(decisionFlag == 0){
            break;
        }else{
            printf("1と0以外は入れられません。入力ミスです\n");
            continue;
        }
    }while(decisionFlag == 0);
    return decisionFlag;
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
        clearBuffer();
    }

    while(fgets(buffer, sizeof(buffer), fp) !=NULL){
        name = strtok(buffer, ",");
        address = strtok(NULL, ",");
        tel = strtok(NULL, ",");
        if(strstr(name, searchName) != NULL) {
        printf("名前:%-s\n住所:%-s\nTEL:%-s", name,address,tel);
        }
        printf("さらに検索を続けますか？(y/n)----");
        scanf("%5s%*[^\n]", yesno);

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
 * clearBuffer : バッファをクリア、エラーメッセージをプリント
 *   引数: なし
 *   戻り値:なし
 * ----------------------------------------------------------- */

void clearBuffer()
{
    scanf("%*s");
    printf("数値以外のものが入力されました。\n");
}
