#include <stdio.h>
struct node
{
    int value;
    struct node *next;
} *head = NULL, *tail = NULL;
int top = -1;
void push()
{
    printf("Value: ");
    int n;
    scanf("%d", &n);
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->value = n;
    new->next = NULL;
    top++;
    if (head == NULL)
    {
        head = new;
        tail = new;
    }
    else
    {
        new->next = head;
        head = new;
    }
}

void pop()
{
    if (top >= 0)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    else printf("Stack is empty");
}

void display(struct node *temp)
{
    // Base case
    if (temp == NULL)
        return;

    // print the list after temp node
    display(temp->next);

    // After everything else is printed, print temp
    printf("%d,  ", temp->value);


    // if (head == NULL)
    //     printf("\Empty!!!\n");
    // else
    // {
    //     struct node *t = head;
    //     while (t!= NULL)
    //     {
    //         printf("%d ", t->value);
    //         t = t->next;
    //     }
    //     printf("->");
    // }
    
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Print\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            
            push();
        }
        else if (choice == 3)
        {
            display(head);
        }
        else if (choice == 2)
        {
            pop();
        } else if (choice == 4)
        {
            break;
        }
        else printf("Unknown choice");
        
    }
}