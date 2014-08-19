#include<stdio.h>

int fibo(int);

int main()
{
    int n;
    for (n = 1; n < 30; n++)
        printf("F(%d) = %d\n", n, fibo(n));

    return 0;
}

int fibo(int n)
{
    switch (n) {
        case 1:
        case 2:
            return 1;
        default:
            return fibo(n - 1) + fibo(n - 2);
    }
}

