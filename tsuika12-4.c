#include<stdio.h>

struct xyz {
    int x;
    long y;
    double z;
};
/*------------------------------------------------------------*
 * set_xyz: 構造体の変数の中に、引数でセットした値を入れる。
 *   引数：構造体xyz。数値型x(50) long型y(99999999L) 小数点z(3.14)
 *   戻り値：なし
 *   エラー時の処理：なし
 * ----------------------------------------------------------- */

void set_xyz(struct xyz *p, int x, long y, double z)
{

    p->x = x;
    p->y = y;
    p->z = z;

}

int main(void)
{
    struct xyz sa;

    set_xyz(&sa, 50, 99999999L, 3.14);

    printf("sa.x = %d\n", sa.x);
    printf("sa.y = %ld\n", sa.y);
    printf("sa.z = %f\n", sa.z);

    return 0;

}
