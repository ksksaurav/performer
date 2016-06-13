
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
    graph->V = V+1;
 
    graph->array = (struct AdjList*) malloc((V+1) * sizeof(struct AdjList));
 
    int i;
    for (i = 1; i < V+1; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest)
{

    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}
 
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 1; v < graph->V+1; v++)
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
 
int main()
{
    int V;
    scanf ("%d", &V);
    struct Graph* graph = createGraph(V);
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
 
    printGraph(graph);
 
    return 0;
}