#include<stdio.h>

struct xyz {
    int x;
    long y;
    double z;
};

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
