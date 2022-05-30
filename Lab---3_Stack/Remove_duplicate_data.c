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
    // struct node *temp = head, *temp1, *duplicate;
    // while (temp != NULL && temp->next != NULL)
    // {
    //     temp1 = temp;
    //     while (temp1->next != NULL)
    //     {
    //         if (temp->value == temp1->next->value)
    //         {
    //             temp1->next = temp1->next->next;
    //             free(temp1->next);
    //             // temp1 = temp1->next;
    //         }
    //         else
    //         {
    //             temp1 = temp1->next;
    //         }
    //     }
    //     // temp1 = head;
    //     temp = temp->next;
    // }

    // struct node *p, *q, *prev, *temp;
    // p = q = prev = head;
    // q = q->next;
    // while (p != NULL)
    // {
    //     while (q != NULL && q->value != p->value)
    //     {
    //         prev = q;
    //         q = q->next;
    //     }
    //     if (q == NULL)
    //     {
    //         p = p->next;
    //         if (p != NULL)
    //         {
    //             q = p->next;
    //         }
    //     }
    //     else if (q->value == p->value)
    //     {
    //         prev->next = q->next;
    //         temp = q;
    //         q = q->next;
    //         free(temp);
    //     }
    //     p = p->next;
    // }

    struct node *temp, *temp1;
    temp = head;
    /* Pick elements one by one */
    while (temp != NULL && temp->next != NULL)
    {
        temp1 = temp;
        /* Compare the picked element with rest
           of the elements */
        while (temp1->next != NULL)
        {
            /* If duplicate then delete it */
            if (temp->value == temp1->next->value)
            {
                /* sequence of steps is important here */
                struct node *dlt = temp1->next;
                temp1->next = temp1->next->next;
                free(dlt);
            }
            else /* This is tricky */
                temp1 = temp1->next;
        }
        temp = temp->next;
    }
}