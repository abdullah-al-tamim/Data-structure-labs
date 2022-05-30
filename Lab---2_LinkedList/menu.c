#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
struct node *head = NULL, *tail = NULL;
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
void remove_duplicate(){
    struct node *temp = head;
    struct node *temp1;
    while (temp!=NUll)
    {
        temp1 = temp;
        while (temp1!=NUll)
        {
            if (temp)
            {
                /* code */
            }
            
            struct node *delete;
            
        }
        
    }
    
}
int main()
{
    int choice;
    create();
    display();
    for (int i = 0; i >= 0; i++)
    {
        printf("1. insert a new node at beginning \n");
        printf("2. insert node at any position\n");
        printf("3. insert node at end\n");
        printf("4. delete node from beginning\n");
        printf("5. delete node from ending\n");
        printf("6. delete node from any position\n");
        printf("7. reverse linked list\n");
        printf("8. remove duplicate data from linked list\n");
        printf("9. exit program\n");
        printf("10. Print linked list\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert_at_beg();
            display();
        }
        else if (choice == 2)
        {
            insert_at_mid();
            display();
        }
        else if (choice == 3)
        {
            insert_at_end();
            display();
        }
        else if (choice == 4)
        {
            deleting_first();
            display();
        }
        else if (choice == 5)
        {
            deleting_last();
            display();
        }
        else if (choice == 6)
        {
            deleting_mid();
            display();
        }
        else if (choice == 8){
            remove_duplicate();
        }
        else if (choice == 9)
        {
            break;
        }
        else if(choice == 10){
            display();
        }
    }
}
void deleting_first()
{
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
}
void deleting_last()
{
    struct node *temp, *temp1;
    if (head != NULL)
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        free(temp);
        tail = temp1;
    }
}

void deleting_mid()
{
    struct node *temp, *temp1;
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (head != NULL)
    {
        temp = head;
        for (int i = 0; i < pos; i++)
        {
            temp1 = temp;      // temp1 will be containing the previous node's address
            temp = temp->next; // temp will be containing the next node's address
        }
        temp1->next = temp->next;
        free(temp);
    }
    else
        printf("Item not found");
}
void insert_at_end()
{
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d", &new->value);
    new->next = NULL;
    if (head == NULL)
    {
        /* code */
        head = new;
        tail = new;
    }
    else
    {
        tail->next = new;
        tail = new;
    }
}
void insert_at_mid()
{
    struct node *new, *temp, *temp1, *current;
    int pos;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Insert the value: ");
    scanf("%d", &new->value);
    new->next = NULL;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (head == NULL)
    {
        /* code */
        head = new;
        tail = new;
    }
    else
    {
        temp = head;
        for (int i = 0; i < pos; i++)
        {
            temp1 = temp;      // temp1 will be containing the previous node's address
            temp = temp->next; // temp will be containing the next node's address
        }
        temp1->next = new;
        new->next = temp;
    }
}

void insert_at_beg()
{
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &new->value);
    new->next = NULL;
    if (head == NULL)
    {
        /* code */
        head = new;
        tail = new;
    }
    else
    {
        new->next = head;
        head = new;
    }
}