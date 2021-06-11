#include <stdio.h>
#include <stdlib.h>

typedef struct G
{
    int nn;
    int **Ma;
    int mas[10][10];
} Graph;

void printAllDis (Graph *g, int idx, int source, int dis, int *visited)
{
    if (visited[source])
    {
        return;
    }
    visited[source] = 1;
    if (source == idx)
    {
        visited[idx] = 0;
        printf("%d \n", dis);
        return;
    }
    
    for (int i = 0; i < g->nn; i++)
    {
        if (g->mas[source][i])
        {
            //printf("Goint from %d to %d \n", source, i);
            printAllDis(g, idx, i, dis + 1, visited);
        }
        
    }
    
}

int main () {

    Graph *g = (Graph *) calloc(1, sizeof(Graph));
    /*g->Ma = (int **) calloc(5, sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        g->Ma[i] = (int *) calloc(1, sizeof(int));
    }*/
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            g->mas[i][j] = 0;
        }
        
    }
    
    g->nn = 5;
    g->mas[0][1] = 1;
    g->mas[0][2] = 1;
    g->mas[2][3] = 1;
    g->mas[3][1] = 1;
    g->mas[0][4] = 1;
    g->mas[4][1] = 1;

    int *visited = (int *) calloc(10, sizeof(int));
    printAllDis(g, 1, 0, 0, visited);
    

    return 0;
}
