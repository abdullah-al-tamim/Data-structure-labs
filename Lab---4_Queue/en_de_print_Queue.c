#include <stdio.h>
int queue[100], front = -1, rear = -1;
void create(int size, int value)
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
        printf("%d is deleted", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("%d is deleted from the queue", queue[front]);
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
int main()
{
    int choice;
    while (1)
    {
        printf("\n\n1. Create a queue/Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. print the queue");
        printf("\n4. exit the program");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nEnter the size: ");
            int size;
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                int value;
                scanf("%d", &value);
                create(size, value);
            }
        }
        else if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            break;
        }
    }
}
