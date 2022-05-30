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
int size_count()
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void create(int a)
{
    struct node *temp;
    int n;

    temp = (struct node *)malloc(sizeof(struct node));
    // scanf("%d", &a);
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

void deleting_mid(int size)
{
    struct node *temp, *temp1;
    int pos;
    if (size % 2 == 1)
    {
        pos = (size / 2) + 1;
        if (head != NULL)
        {
            temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = temp->next;
            free(temp);
        }
        else
            printf("Item not found");
    }
    else if (size % 2 == 0)
    {
        pos = size / 2;
        for (int i = 0; i < 2; i++)
        {
            if (head != NULL)
            {
                temp = head;
                for (int i = 0; i < pos - 1; i++)
                {
                    temp1 = temp;
                    temp = temp->next;
                }
                temp1->next = temp->next;
                free(temp);
            }
            else
                printf("Item not found");
        }
    }
}

int main()
{
    printf("ENter data: ");
    int val;
    while (1)
    {
        scanf("%d", &val);
        if (val >= 0)
        {
            create(val);
        }
        else
            break;
    }

    // create();
    display();
    int size = size_count();

    printf("There are total %d items", size);
    deleting_mid(size);
    printf("\n");
    display();
}
