#include <stdio.h>
int average(int *p)
{
    int sum = 0;
    for (int j = 0; j < 5; j++)
    {
        sum += *(p + j);
    }
    return sum/5;
}
int deference(int avg, int i)
{
    return avg-i;
}
int main()
{
    int arr[5] = {10,2,3,4,5,};
    int *ptr;
    ptr = arr;
    int avg = average(ptr);
    printf("%d\n", avg);
    for(int i=0; i<5; i++) 
    {
        printf("%d, ", deference(avg, arr[i]));
    }
}