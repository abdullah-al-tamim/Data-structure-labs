#include <stdio.h>

int lcm(int n, int m)
{
    // int flag = 0;
    int min = n < m ? n : m;
    int max = n > m ? n : m;
    static int v = 0;
    v += max;
    if (v % min == 0 && v % max == 0)
    {
        return v;
    }
    else
        return lcm(min, max);
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    printf("LCM: %d", lcm(n, m));
}