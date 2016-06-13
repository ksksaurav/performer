#include <stdio.h>
#include <stdlib.h>
 

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 

struct AdjList
{
    struct AdjListNode *head;  
};
 
struct Graph
{
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}

void BFSG(int s);
void BFST(int s);

void addEdge(struct Graph* graph, int src, int dest)
{
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 1; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int distG[1000000];
int distT[1000000];

struct Graph *graph;
struct Graph *graph2;

int main()
{
    int V;
    scanf ("%d", &V);
    // struct Graph* graph = createGraph(V+1);
    graph = createGraph(V+1);
    int i;

    for (i = 0; i < V; i++)
    {
        int vert, no_neghs;
        scanf("%d%d", &vert, &no_neghs);
        int j;
        for (j = 0; j < no_neghs; j++)
        {
            int neigh;
            scanf("%d", &neigh);
            addEdge(graph, vert, neigh);
        }

    }
 
    //printGraph(graph);
    

    graph2 = createGraph(V+1);
    int root, M;
    scanf("%d%d", &root, &M);

    for (i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d%d", &u,&v);
        addEdge (graph2, u, v);
    }

    //printGraph(graph2);

    BFSG(root);
    BFST(root);

    // printf("%d ", V);


    for(i = 1; i < V+1; i++)
    {
        printf("%d ", distG[i]);
    }


    for(i = 1; i < V+1; i++)
    {
        printf("%d ", distT[i]);
    }
    return 0;
}

void BFSG(int s)
{
    int visited[100001], i, j;
    for(i = 1; i < 1e5+1; i++)
        visited[i] = 0;
    
    int array[1000005];
    int head=1 , tail = 1;
    visited[s] = 1;
    distG[s] = 0; 
    tail++;

    while(head != tail)
    {
        int current = array[head];
        printf("%d\n", current);
        head++;

        int v;
        
        struct AdjListNode* pCrawl = graph->array[current].head;
        // printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            if (visited[pCrawl->dest] == 0)
            {
                array[tail++] = pCrawl->dest;
                distG[pCrawl->dest] = distG[current] + 1;
                visited[pCrawl->dest] = 1;
            }

            pCrawl = pCrawl->next;
        }   
    }

}


void BFST(int s)
{
    int visited[100001], i, j;
    for(i = 1; i < 1e5+1; i++)
        visited[i] = 0;
    
    int array[1000005];
    int head=1 , tail = 1;
    visited[s] = 1;
    tail++;
    distT[s] = 0; 

    while(head != tail)
    {
        int current = array[head];
        printf("%d\n", current);
        head++;

        int v;
        
        struct AdjListNode* pCrawl = graph2->array[current].head;
        // printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            if (visited[pCrawl->dest] == 0)
            {
                array[tail++] = pCrawl->dest;
                distT[pCrawl->dest] = distT[current] + 1;
                visited[pCrawl->dest] = 1;
            }

            pCrawl = pCrawl->next;
        }   
    }

}