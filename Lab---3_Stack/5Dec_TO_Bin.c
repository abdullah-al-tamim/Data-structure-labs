#include <stdio.h>
int top = -1;
int stack[100];
void push(int ele)
{
    stack[++top] = ele;
}
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    int ele;
    if (n==0) 
    {
        push(0);
    }
    
    while (n > 0)
    {
        ele = n % 2;
        n = n / 2;
        push(ele);
    }
    printf("The number in binary: ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d", stack[i]);
    }
}