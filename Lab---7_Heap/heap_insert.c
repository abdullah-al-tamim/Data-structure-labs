#include <stdio.h>
int heap[100], count = 0;

void swap(int position, int parent)
{
    int temp = heap[position];
    heap[position] = heap[parent];
    heap[parent] = temp;
}

void reheapUp(int position)
{
    int parent;
    if (position > 1)
    {
        parent = position / 2;
        if (heap[position] > heap[parent])
        {
            swap(position, parent);
            reheapUp(parent);
            return;
        }
    }
}

void insert(int data)
{
    if (count == 100)
    {
        printf("Heap overflow");
        return;
    }
    else
    {
        count++;
        heap[count] = data;
        reheapUp(count);
    }
}

void ReheapDown(int position, int lastPosition)
{
    int leftchild = position * 2;
    int rightchild = position * 2 + 1;
    int largest = position;
    if (leftchild <= lastPosition && heap[leftchild] > heap[largest])
    {
        largest = leftchild;
    }
    if (rightchild <= lastPosition && heap[rightchild] > heap[largest])
    {
        largest = rightchild;
        // return;
    }
    if (position != largest)
    {
        // printf("Hello");
        swap(largest, position);
        ReheapDown(largest, lastPosition);
    }
}

int deleteTop()
{
    int val;
    if (count == 0)
    {
        printf("Heap is empty");
        return;
    }
    else
    {
        val = heap[1];
        heap[1] = heap[count];
        count -= 1;
        ReheapDown(1, count);
    }
    return val;
}

int findsmallest()
{
}

int main()
{
    while (1)
    {
        printf("\n====================\n");
        printf("\tMAX HEAP");
        printf("\n1. Insert");
        printf("\n2. Print heap");
        printf("\n3. Delete the top");
        // printf("\n4. Smallest element");
        printf("\n5. Largest element");
        printf("\n6. sort");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        // printf("\n====================\n");

        if (choice == 1)
        {
            printf("Enter data: ");
            int data;
            scanf("%d", &data);
            insert(data);
        }
        else if (choice == 2)
        {
            for (int i = 1; i <= count; i++)
            {
                printf("%d ", heap[i]);
            }
        }
        else if (choice == 3)
        {
            deleteTop();
        }
        // else if (choice == 4)
        // {
        //     findsmallest();
        // }
        else if (choice == 5){
            printf("The maximum is: %d", heap[1]);
        }
        else if (choice == 7)
        {
            break;
        }
    }
}