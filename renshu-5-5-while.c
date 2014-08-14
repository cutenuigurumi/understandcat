#include<stdio.h>

int main()
{
//n 入力される数値 cnt 全体の入力件数 cnt40 40以上の数値の個数
    int cnt = 0, cnt40 = 0,n;

    while(cnt < 10){
        printf("数値を入力して下さい。(99で終了)----");
        scanf("%d", &n);
        if(n != 99){
            if (n >= 40) {
                printf("%d\n", n);
                cnt40 = cnt40 + 1;
                cnt = cnt + 1;
                continue;
            } else {
            cnt = cnt + 1;
            continue;
            }
        } else {
        break;
        }
    }

printf("40以上のデータ数は%d件です\n", cnt40);
}
