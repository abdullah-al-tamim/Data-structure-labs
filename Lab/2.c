#include <stdio.h>
int main()
{
    int a, b, c, *p, *q, *r;
    p = &a;
    q = &b;
    r = &c;
    scanf("%d", p);
    scanf("%d", q);
    scanf("%d", r);
    if (*p>=*q&&*p>=*r)
    {
        printf("%d", *p);
    }
    else if (*q >= *p && *q >= *r)
    {
        printf("%d", *q);
    } else printf("%d", *r);
}