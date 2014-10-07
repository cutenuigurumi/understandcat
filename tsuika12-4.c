#include<stdio.h>

struct xyz {
    int x;
    long y;
    double z;
};
/*------------------------------------------------------------*
 * set_xyz: xとzを入れ替える
 *   引数：構造体xyz。数値型x long型y 小数点z
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
