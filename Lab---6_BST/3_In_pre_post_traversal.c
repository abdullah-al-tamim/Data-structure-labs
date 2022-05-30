#include <stdio.h>
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

void inorder(struct node *root)
{
    if (root!=NULL)
    {
        /* code */
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    
}

void preorder(struct node *root)
{
    if (root!=NULL)
    {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int n, size;
    printf("Enter size: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &n);
        root = insert(root, n);
    }
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
}