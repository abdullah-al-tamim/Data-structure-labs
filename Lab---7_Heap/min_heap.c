#include <stdio.h>
int heap[100];
int count = 0;

void insert(int data)
{
    if (count == 100)
    {
        printf("Heap overflown");
        return;
    }
    else
    {
        count++;
        heap[count] = data;
        reheapUp(count);
        return;
    }
}

void reheapUp(int pos)
{
    int parent = pos / 2;
    if (count > 1)
    {
        if (heap[pos] < heap[parent])
        {
            swap(pos, parent);
            reheapUp(parent);
        }
    }
}

void swap(int pos, int parent)
{
    int temp = heap[pos];
    heap[pos] = heap[parent];
    heap[parent] = temp;
}

void reheapDown(int pos, int lastpos)
{
    int left = pos * 2;
    int right = pos * 2 + 1;
    int smallest = pos;
    if (left <= lastpos && heap[left] < heap[smallest])
    {
        smallest = left;
    }
    if (right <= lastpos && heap[right] < heap[smallest])
    {
        smallest = right;
    }
    if (smallest != pos)
    {
        swap(smallest, pos);
        reheapDown(smallest, lastpos);
        // return;
    }
}
int delete ()
{
    if (count == 0)
    {
        printf("Heap is empty");
        return;
    }
    int data = heap[1];
    heap[1] = heap[count];
    count--;
    
    reheapDown(1, count);
    for (int i = 1; i <= count; i++)
    {
        printf("%d ", heap[i]);
    }
    return data;
}

int main() // 1 10 1 15 1 30 1 40 1 150 1 100 1 40
{
    while (1)
    {
        printf("\n====================\n");
        printf("\tMIN HEAP");
        printf("\n1. Insert");
        printf("\n2. Print heap");
        printf("\n3. Delete the top");
        // printf("\n4. Smallest element");
        printf("\n5. smallest element");
        printf("\n6. sort");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            int data;
            printf("Enter data: ");
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
            printf("\n%d is deleted", delete ());
        }
        else if (choice == 6)
        {
            // for (int i = count / 2; i >= 1; i--)
            // {
            //     reheapDown(i, count);
            // }
            // printf("%d ", size);
            for (int i = count; i >= 1; i--)
            {
                swap(i, 1);
                reheapDown(1, i - 1);
            }
        }
    }
}
