#include<stdlib.h>
#include<stdio.h>

/*edge list structure for each edge */
typedef struct{
    unsigned int first;
    unsigned int second;
}edge;


static unsigned int dfs(const edge *edges,unsigned int n, unsigned int *visited,unsigned int order, unsigned int vertex, unsigned int predecessor)
{
    unsigned int i;
    unsigned int cycle=0;
    visited[vertex]=1;
    for(i=0;i<n && !cycle;i++)
    {
        if(edges[i].first==vertex || edges[i].second==vertex)
        {
            const unsigned int next=edges[i].first== vertex? edges[i].second : edges[i].first;
            if(visited[next]==0)
            {
                cycle=dfs(edges,n,visited,order,next,vertex);
            }
            else if(next!=predecessor)
            {
                cycle=1;
            }
        }
    }
    return cycle;
}
unsigned int cycle_finder(const edge *edges , unsigned int n, unsigned int order)
{
   unsigned int *cyc=calloc(order,sizeof(unsigned int));
   unsigned int cycle;
   if (cyc==NULL)
   {
       return 0;
   }
   cycle=dfs(edges,n,cyc,order,0,0);
   free(cyc);
   return cycle;
}


/* DO NOTE THAT THE GRAPH TRAVERSAL IN THIS QUESTION ALWAYS STARTS WITH NODE 0  so you need not take any input for starting node */
int main(void)
{
    unsigned int order;  /* number of vertices */
    unsigned int n; /* number of edges */
    scanf("%d", &n);
    scanf("%d", &order);
    edge *edges;
    unsigned int ans;
    edges = malloc(n*sizeof(edge));
    if(edges==NULL)
    {
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        scanf("%d", &edges[i].first);
        scanf("%d", &edges[i].second);
    }
        
    ans= cycle_finder(edges, n, order);
    printf(ans? "cyclic":"acyclic");
    free(edges);
    return 0;

}