#include <stdio.h>
#include <stdlib.h>
struct AdjListNode {
	int dest;
	struct AdjListNode* next;
};
struct AdjList {
	struct AdjListNode* head;
};
struct Graph {
	int V;
	struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode= (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}
struct Graph* createGraph(int V)
{
	struct Graph* graph= (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;
	return graph;
}
void addEdge(struct Graph* graph, int src, int dest)
{
	struct AdjListNode* check = NULL;
	struct AdjListNode* newNode = newAdjListNode(dest);

	if (graph->array[src].head == NULL) {
		newNode->next = graph->array[src].head;
		graph->array[src].head = newNode;
	}
	else {
		check = graph->array[src].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}
	newNode = newAdjListNode(src);
	if (graph->array[dest].head == NULL) {
		newNode->next = graph->array[dest].head;
		graph->array[dest].head = newNode;
	}
	else {
		check = graph->array[dest].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}
}
void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v) {
		struct AdjListNode* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl) {
			printf("-> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}
int main()
{
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printGraph(graph);
	return 0;
}
