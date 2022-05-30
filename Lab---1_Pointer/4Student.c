#include <stdio.h>
struct student{
    char name[100];
    int id;
    float cg;
};


int main()
{
    int n;
    scanf("%d", &n);
    struct student *ptr;
    ptr= (struct student *)malloc(sizeof(struct student)*n);
    for(int i=0; i<n; i++){
        scanf("%s %d %f", &(ptr + i)->name, &(ptr + i)->id, &(ptr + i)->cg);
        // scanf("%d", (ptr+i)->id);
        // scanf("%f", (ptr+i)->cgpa);

    }
    double max = ptr ->cg;
    int index = 0;
    for (int i = 0; i<n; i++){
        if ((ptr+i)->cg >= max)
        {
            max = (ptr+i)->cg;
            index = i;
        }
        
    }
    printf("Name: %s\n", (ptr+index)->name);
    // for(int i=0; i<n; i++) {
    //     printf("%s", (ptr+i)->name);
    //     printf("%d", (ptr+i)->id);
    // }
}