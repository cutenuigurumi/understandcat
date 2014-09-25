#include<stdio.h>

int main(void)
{
    struct xyz{
        int x;
        long y;
        double z;
    } ;

    struct xyz sa = {50, 99999999L, 3.14}, *pt;
    pt = &sa;

    printf("sa.x = %d\n", pt->x);
    printf("sa.y = %ld\n", pt->y);
    printf("sa.z = %f\n", pt->z);

}
