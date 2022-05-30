#include <stdio.h>
int queue[100], front = -1, rear = -1;
int qq[100], front2 = -1, rear2 = -1;
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
void copyQueue(int size){
    for (int i = 0; i < size; i++)
    {
        if (front2 ==-1 && rear2 == -1)
        {
            front2++;
            rear2++;
            qq[front2] = queue[front];
        }
        else{
            rear2++;
            qq[rear2] = queue[i];
        }
    }
    
}
void display()
{
    if (front2 == -1 && rear2 == -1)
    {
        /* code */
        printf("queue is empty");
    }
    else
    {
        for (int i = front2; i <= rear2; i++)
        {
            printf("%d ", qq[i]);
        }
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
        create(size, value);
    }
    copyQueue(size);
    display();
}