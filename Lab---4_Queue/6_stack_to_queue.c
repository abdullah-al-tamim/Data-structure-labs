#include <stdio.h>
int stack[50], queue[50];
int top = -1, front = -1, rear = -1;

void push(int value)
{
    top++;
    stack[top] = value;
}

void pop()
{
    enqueue(stack[top]);
    top--;
}

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
    printf("Enter the size of stack: ");
    int n;
    scanf("%d", &n);
    printf("Enter the values: ");
    int a;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        push(a);
    }
    for (int i = 0; i < n; i++)
    {
        pop();
    }

    printf("The queue: ");
    display();
}