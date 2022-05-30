#include <stdio.h>
void sortarray(int n, int *p)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if (*(p+i)>=*(p+j))
            {
                  int temp = *(p+i);
                  *(p+i) = *(p+j);
                  *(p+j) = temp;  
            }
            
        }
    }
}
int main()
{
    int arr[5], *p;
    p = arr;//p = &arr[0];
    for(int i = 0; i < 5; i++) {
        scanf("%d", (p+i));
    }
    sortarray(5, p);
    for(int i = 0; i < 5; i++) {
        printf("%d, ", *(p+i));
    }
}