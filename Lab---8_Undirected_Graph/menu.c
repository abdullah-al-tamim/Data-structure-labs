#include <stdio.h>
int graph[100][100];
int ver, edge;
int main()
{
    while (1)
    {
        printf("\n=============================\n");
        printf("\tUNDIRECTED GRAPH");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Add a Vertex");
        printf("\n4. Add edge");
        printf("\n5. Remove vertices");
        printf("\n6. Depth First Traversal");
        printf("\n7. Breadth First Traversal");
        printf("\n8. EXIT PROGRAM");
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the number of vertices: ");
            scanf("%d", &ver);
            printf("Enter the number of edges: ");
            scanf("%d", &edge);
            for (int i = 0; i < edge; i++)
            {
                printf("Enter the %d'th connecting vertices: ", i + 1);
                int x, y;
                scanf("%d%d", &x, &y);
                graph[x][y] = 1;
                graph[y][x] = 1;
                for (int j = 0; j < ver; j++)
                {
                    for (int k = 0; k < ver; k++)
                    {
                        if (graph[j][k] != 1)
                        {
                            graph[j][k] = 0;
                        }
                    }
                }
            }
        }
        else if (choice == 2) //display
        {
            for (int i = 0; i < ver; i++)
            {
                for (int j = 0; j < ver; j++)
                {
                    printf("%d ", graph[i][j]);
                }
                printf("\n");
            }
        }
        else if (choice == 3) //add vertex
        {
            ver++;
            edge++;
            for (int i = 0; i < ver; i++)
            {
                graph[i][ver-1] = 0;
                graph[ver-1][i] = 0;
            }
        }
        else if (choice == 4) //add edge
        {
            edge++;
            printf("Enter connecting vertices: ");
            int x, y;
            scanf("%d", &x);
            scanf("%d", &y);
            if (x<= ver && y<= ver)
            {
                graph[x][y] = 1;
                graph[y][x] = 1;

            }
            
        }
        else if (choice == 5) //delete vertex
        {
            
        }
    }
}