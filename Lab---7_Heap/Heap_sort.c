#include <stdio.h>
void swap(int arr[], int largest, int pos)
{
    int temp = arr[largest];
    arr[largest] = arr[pos];
    arr[pos] = temp;
}

void heapify(int arr[], int last, int pos)
{
    int left = pos * 2;//6
    int right = pos * 2 + 1;//
    int largest = pos;//3
    if (left <= last && arr[left] > arr[largest])
    {
        largest = left;//6
    }
    if (right <= last && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != pos)

    {
        swap(arr, largest, pos);
        heapify(arr, last, largest);
    }
}

int main()
{
    printf("Enter the size: ");
    int size;
    scanf("%d", &size);
    int heap[size];
    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &heap[i]);
    }
    for (int i = size / 2; i >= 1; i--)
    {
        heapify(heap, size, i);
    }
    printf("\nMax heap: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    for (int i = size; i>=1; i--)   
    {
        int temp = heap[i];
        heap[i] = heap[1];
        heap[1] = temp;
        heapify(heap, i-1, 1);
    }
    printf("\nSorted array: ");
    for (int i = 1; i <= size; i++){
        printf("%d ", heap[i]);
    }
    printf("\nMaximum: %d", heap[size]);
    
}