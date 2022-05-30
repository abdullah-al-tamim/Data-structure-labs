#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
struct node *head = NULL, *tail = NULL;
// void display()
// {
//     struct node *temp = head;
//     while (temp != NULL)
//     {
//         printf("%d ", temp->value);
//         temp = temp->next;
//     }
//     printf("\n");
// }
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
struct node * reverse(struct node *fhead)
{
    if (fhead->next==NULL)
    {
        fhead = fhead;
        return fhead;
    }
    struct node *temp;
    temp = reverse(fhead->next);
    fhead->next->next = fhead;
    fhead->next = NULL;
    return temp;

}
int main()
{
    create();
    struct node *temp = reverse(head);
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}