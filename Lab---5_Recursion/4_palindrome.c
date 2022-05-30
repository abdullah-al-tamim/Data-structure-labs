#include <stdio.h>
#include<math.h>
int palindrome(int n)
{
    if (n==reverse(n))
    {
        return 1;
    }
    else return 0;
    
}

int reverse(int n)
{
    int dig = (int) log10(n);
    if (n==0    )
    {
        /* code */
        return 0;
    }
    
    else return ((n%10*pow(10, dig))+reverse(n/10));
}

int main()
{
    int n;
    scanf("%d", &n);
    int ret = palindrome(n);
    if (ret==1)
    {
        printf("palindrome");
    }else printf("not palindrome");
    
}