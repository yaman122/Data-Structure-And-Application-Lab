#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 50
#define INFINITY 9999

typedef struct graph
{
    int n;                         /* Number of vertices in graph */
    int adj[MAX_NODES][MAX_NODES]; /* Adjacency matrix */
} Graph;

// creates the graph
void create_graph(Graph *adj_mat)
{

    int i, j;
    for (int i = 0; i < adj_mat->n; i++)
    {
        for (int j= 0; j< adj_mat->n; j++)
        {
            adj_mat->adj[i][j] = 0;
        }
    }
    while (1==1)
    {
        // edge between two vertex
        scanf("%d %d\n", &i, &j);
        if (i < 0 && j <= 0 || i >= adj_mat->n || j >= adj_mat->n)
        {
            break;
        }
        adj_mat->adj[i][j] = 1;
    }
}
// helper functions for inserting an element into a queue
void append(int *queue, int v, int *pqr)
{
    ++(*pqr);
    queue[*pqr] = v;
}
// helper function to delete from a queue
int delete (int *queue, int *pqr)
{
    int res = queue[0];
    for (int i = 0; i < *pqr; ++i)
    {
        queue[i] = queue[i + 1];
    }
    --(*pqr);
    return res;
}

void breadthFS(Graph *adj_mat, int source, int dest, int *prev)
{
    int queues[adj_mat->n];
    for (int i = 0; i < (adj_mat->n); i++)
        queues[i] = 0;
    int fi = 0, ro = -1;

    int visited[adj_mat->n];
    for (int i = 0; i < (adj_mat->n); i++)
        visited[i] = -99;

    queues[++ro] = source;
    visited[source] = 1;

    int k, i;
    while (fi <= ro)
    {
        k = queues[fi++];
        for (int i = 0; i < (adj_mat->n); i++)
        {
            if ((adj_mat->adj)[k][i] && (visited[i] == -99))
            {
                queues[++ro] = i;
                visited[i] = 1;
                prev[i] = k;
            }
        }
    }
}

// bfs function to calculate the minimum distance
// You are required to complete this function
int find_dist(Graph *adj_mat, int source, int dest)
{

    int prev[adj_mat->n];
    for (int i = 0; i < (adj_mat->n); i++)
        prev[i] = -99;

    breadthFS(adj_mat, source, dest, prev);

    int path[(adj_mat->n)];
    int l = 0;
    for (int i = dest; i != -99; i = prev[i])
        path[l++] = i;

    int temp;
    for (int i = 0; i < l / 2; i++)
    {
        temp = path[i];
        path[i] = path[l - i - 1];
        path[l - i - 1] = temp;
    }

    if (path[0] == source)
        return l - 1;

    return -1;
}

int main()
{
    Graph adj_mat;

    int source, dest;

    // number of vertex
    scanf("%d\n", &adj_mat.n);
    // creates adj matrix
    create_graph(&adj_mat);

    // source vertex
    scanf("%d\n", &source);

    // destination vertex
    scanf("%d", &dest);

    int result = find_dist(&adj_mat, source, dest);
    printf("%d", result);
    return 0;
}