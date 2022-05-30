#include <stdio.h>
char queue[100], front = -1, rear = -1;
void enque(char value)
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
        printf("%s", queue);
        // printf("\n%d", rear);
    }
    // we are the students of CSE
}
int main()
{
    char str[100];
    printf("Enter the string: ");
    gets(str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            enque(str[i]);
        }
    }
    display();
}