#include <stdio.h>
int GCD(int m, int n)
{
    if (m == 0)
    {
        return n;
    }
    else if (n == 0)
    {
        return m;
    }
    else
    {
        return GCD(n, m % n);
    }
}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d", GCD(m, n));
}
