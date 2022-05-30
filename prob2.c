#include <stdio.h>
#include <math.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL;

struct node *insert(struct node *root, int item)
{
    if (root == NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        root = newnode;
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else if (item < root->data)
    {
        root->left = insert(root->left, item);
        return root;
    }
    else
    {
        root->right = insert(root->right, item);
        return root;
    }
}

void print_siblings(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_siblings(root->left);
    print_siblings(root->right);

    if (root->left != NULL && root->right != NULL)
    {

        printf("%d and %d are siblings", root->left->data, root->right->data);
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int array[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < size; i++)
    {
        root = insert(root, array[i]);
    }

    print_siblings(root);
}