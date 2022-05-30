#include <stdio.h>
int top = -1;
char stack[100];
void push(char c)
{
    top++;
    stack[top] = c;
}

void pop()
{
    top--;
}

int main()
{
    char arr[100];
    scanf("%s", &arr);
    int flag = 1;
    for (int i = 0; arr[i] != NULL; i++)
    {
        if (arr[i] == '(')
        {
            push(arr[i]);
        }
        else if (arr[i] == ')')
        {
            if (top == -1)
            {
                printf("Closing parentheses not matched");
                flag = 0;
                break;
            }
            else
                pop();
        }
    }
    if (top == -1 && flag == 1)
    {
        printf("Perfect");
    }
    else if (flag == 1)
        printf("Opening parentheses not end");
}