#include <stdio.h>
struct node
{
    int value;
    struct node *next;
};
struct node n1, n2;
int main()
{
    struct node a;
    int x = a.value = 10;
    printf("%d", x);

}