#include<stdio.h>

int main()
{
    int va[5] = {15, 20, 30, 0, 0}, vb[5], i;

    printf("va vb\n");
    printf("------\n");

    for(i = 0;i < 5; i++){
        vb[i] = va[i];
        printf("%2d %2d\n", va[i], vb[i]);
    }


}
