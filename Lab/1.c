#include<stdio.h>
int main()
{
    double d = 1.5, *dPtr;
    dPtr = &d;
    printf("\nDouble: address:- %p, value:- %f\n",  dPtr, *dPtr);
    int n = 5, *nPtr;
    nPtr = &n;
    printf("Int: address:- %p, value:- %d\n", nPtr, *nPtr);
    char s[5] = "hello";
    char *sPtr;
    sPtr = s;
    printf("String: address:- %p\n", sPtr);
    for(int i = 0; i < 5; i++)
    {
        printf("%c", *sPtr++);
    }
}