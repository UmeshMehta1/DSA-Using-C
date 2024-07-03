#include <stdio.h>

int fac();

int main()
{
    int n;
    printf("enter num: ");
    scanf("%d", &n);
    int res = fac(n);
    printf("%d", res);
}

int fac(int n)
{

    static int f = 1;
    if (n == 0)
        return f;

    f = f * n;
    n--;

    fac(n);
}