#include <stdio.h>
int main()
{
     int *p, n ;
     scanf("%d", &n);
     p = (int *) malloc(sizeof(int)*n);
     for(int i = 0; i < n; i++)
     {
         scanf("%d", (p+i));
     }
     int max = *p;
     for(int i = 0; i < n; i++)
     {
         if (*(p+i) >= max)
         {
             max = *(p+i);
         }
         
     }
     printf("%d\n", max);
}