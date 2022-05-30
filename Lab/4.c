#include<stdio.h>
int main()
{
    int arr[10], *ptr;
    ptr = arr;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", ptr+i);
    }
    int even[10], odd[10], count1 = 0, count2 = 0, *evenPtr, *oddPtr;
    evenPtr = even;
    oddPtr = odd;
    for(int i = 0; i < 10; i++)
    {
        // printf("%d ", *(ptr+i));
        if (*(ptr+i)%2 == 0)
        {
            even[count1] = *(ptr+i);
            count1++;
        }
        else if (*(ptr + i) % 2 == 1)
        {
            odd[count2] = *(ptr+i);
            count2++;
        }
    }
    for (int i = 0; i < count1; i++)
    {
        printf("%d ", *(evenPtr+i));
    }
    printf("\n");
    for (int i = 0; i < count2; i++)
    {
        printf("%d ", *(oddPtr+i));
    }
}