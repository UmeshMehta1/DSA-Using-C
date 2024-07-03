#include <stdio.h>

int rev();

int main()
{
    int n;
    printf("enter num: ");
    scanf("%d", &n);
    int res = rev(n);
    printf("%d", res);
}

int rev(int n)
{
    int r;
    int s = 0;

    while (n > 0)
    {
        r = n % 10;
        s = s * 10 + r;
        n = n / 10;
    }
    return s;
}