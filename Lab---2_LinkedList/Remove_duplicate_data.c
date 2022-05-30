#include <stdio.h>
struct node
{
    int value;
    struct node *next;
} *head = NULL, *tail = NULL;
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
void create()
{
    struct node *temp;
    int n, a;
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node)); // malloc is reserving 12B storage for the node structure, int = 4B, pointer = 8B;
        scanf("%d", &a);
        temp->value = a;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
}
int main()
{
    create();
    // display();
    remove_duplicate();
    display();
}
void remove_duplicate()
{

    struct node *temp, *temp1;
    temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        temp1 = temp;
        while (temp1->next != NULL)
        {
            if (temp->value == temp1->next->value)
            {
                struct node *dlt = temp1->next;
                temp1->next = temp1->next->next;
                free(dlt);
            }
            else
                temp1 = temp1->next;
        }
        temp = temp->next;
    }
}