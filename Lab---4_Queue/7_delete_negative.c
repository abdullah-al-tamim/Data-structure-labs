#include <stdio.h>
int queue[100], front = -1, rear = -1;

void enqueue(int value)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[front] = value;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        // printf("%d is deleted", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        // printf("%d is deleted from the queue", queue[front]);
        front++;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        /* code */
        printf("queue is empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
void delete_negative()
{
    int flag = 0;
    for (int i = front; i <= rear; i++)
    {
        if (queue[i] < 0)
        {
            flag = 1;
            // printf("%d->",i);
            if (i == front)
            {
                dequeue();
            }
            else
            {
                for (int j = i; j < rear; j++)
                {
                    queue[j] = queue[j + 1];
                }
                rear--;
                i--;
            }
        }
    }
    if (flag == 0)
    {
        printf("There are no negative elements in the queue\n");
    }
}
int main()
{
    printf("\nEnter the size: ");
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }
    // display();
    delete_negative();
    printf("\n");
    display();
}
