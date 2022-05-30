#include<stdio.h>
int main()
{
    int *p, n;
    scanf("%d", &n);
    p = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", p+i);
    }
    for(int i = 0; i < n; i++)
    {
        
        if (*(p+i)<0)
        {
            for(int j=i; j<n-1; j++){
            // printf("%d, ", *(p + j));
                *(p+j) = *(p+(j+1));
            }
            n--;
            i--;
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("%d, ", *(p+i)); 
    }
}