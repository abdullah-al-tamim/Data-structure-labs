#include <stdio.h>

int power(int n, int p)
{

    if (n == 0)
    {
        return 0;
    }
    if (p == 0)
    {
        return 1;
    }
    else
    {
        return n * power(n, p - 1);
    }
}

int main()
{
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);
    printf("%d\n", power(n, p));
}