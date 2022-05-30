#include <stdio.h>
int top = -1;
int stack[100];
void push(int n)
{
    top++;
    stack[top] = n;
}
void pop()
{
    if (top >= -1)
    {
        top--;
    }
}
int main()
{
    int choice;
    int flag = 1;
    while (flag == 1)
    {

        printf("\n================================\n");
        printf("\n1. Ensert data");
        printf("\n2. Pop stack");
        printf("\n3. Print stack");
        printf("\n4. terminate");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            int n;
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top > -1)
            {
                /* code */
                for (int i = 0; i <= top; i++)
                {
                    printf("%d ", stack[i]);
                }
            }
            else
                printf("No elements in stack");

            break;
        case 4:
            flag = 0;
            break;
        }
    }
}