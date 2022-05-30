#include <stdio.h>
int array[50];

void swap(int largest, int position)
{
    int x = array[largest];
    array[largest] = array[position];
    array[position] = x;
}
void heapify(int size, int position)
{
    int left = position * 2;
    int right = position * 2 + 1;
    int largest = position;
    if (left <= size && array[left] > array[largest])
    {

        largest = left;
    }
    if (right <= size && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != position)
    {
        swap(largest, position);
        heapify(size, largest);
    }
}
int main()
{
    int size;
    scanf("%d", &size);
    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &array[i]);
    }
    // turning the array into a max heap
    for (int i = size / 2; i >= 1; i--)
    {
        // heapify function works just like reheapDown
        heapify(size, i);
    }
    printf("\n");
    printf("Max heap: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", array[i]);
    }
    for (int i = size; i >= 1; i--)
    {
        int val = array[i];
        array[i] = array[1];
        array[1] = val;
        heapify(i - 1, 1);
    }
    printf("\nAfter sorting: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", array[i]);
    }
}
