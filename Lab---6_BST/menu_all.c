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

struct node *search(struct node *root, int element)
{
    // int flag = 0;
    if (root == NULL)
    {
        return;
    }

    if (element == root->data)
    {
        return root;
    }
    else if (element < root->data)
    {
        return search(root->left, element);
    }
    else
    {
        return search(root->right, element);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        /* code */
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
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

struct node *maximum(struct node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return maximum(root->right);
}

struct node *minimum(struct node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return minimum(root->left);
}

struct node *deletenode(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deletenode(root->left, data);
        return root;
    }
    else if (data > root->data)
    {
        root->right = deletenode(root->right, data);
        return root;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            /* code */
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root;
            // printf("H");
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else
        {
            struct node *min = minimum(root->right);
            // printf("%d ", min->data);
            root->data = min->data;
            root->right = deletenode(root->right, min->data);
            return root;
        }
    }
}

int main()
{
    int flag = 1;
    while (flag == 1)
    {
        printf("\n======================\n");
        printf("\tBST MENU");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Inorder");
        printf("\n4. Preorder");
        printf("\n5. Postorder");
        printf("\n6. Find minimum");
        printf("\n7. Find maximum");
        printf("\n8. delete");
        printf("\n9. EXIT");
        printf("\n======================");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int data;
            printf("Enter the data: ");
            scanf("%d", &data);
            root = insert(root, data);
        }
        else if (choice == 2)
        {
            struct node *temp;
            int key;
            printf("Enter the element to search: ");
            scanf("%d", &key);
            temp = search(root, key);
            if (temp == NULL)
            {
                printf("No such element!!");
            }
            else
                printf("Element Found!");
        }
        else if (choice == 3)
        {
            printf("Inorder: ");
            inorder(root);
        }
        else if (choice == 4)
        {
            printf("Preorder: ");
            preorder(root);
        }
        else if (choice == 5)
        {
            printf("Postorder: ");
            postorder(root);
        }
        else if (choice == 6)
        {
            struct node *min;
            min = minimum(root);
            printf("Minimum: %d", min->data);
        }
        else if (choice == 7)
        {
            struct node *max;
            max = maximum(root);
            printf("Maximum: %d", max->data);
        }
        else if (choice == 9)
        {
            break;
        }
        else if (choice == 8)
        {
            struct node *temp;
            int n;
            printf("Enter the data to be deleted: ");
            scanf("%d", &n);
            root = deletenode(root, n);
            printf("\n\n%d ", root->data);
        }
    }
}