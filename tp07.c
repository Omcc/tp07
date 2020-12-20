#include <stdio.h>
#include "tp07.h"
#include <string.h>



struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode *p = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	p->next=NULL;
	p->dest=dest;

	return p;
}

struct Graph* createGraph(int V)
{
	struct Graph* p=(struct Graph*)malloc(sizeof(struct Graph));

	struct AdjList *l = (struct AdjList*)malloc(sizeof(struct AdjList));


	l->root = (struct AdjListNode**)malloc(sizeof(struct AdjListNode*)*(V+1));

	for(int i=0;i<=V;i++)
	{
		l->root[i] = NULL;
	}

	p->list=l;
	p->V=V;

	return p;
		
}

void addEdge(struct Graph *graph,int src,int dest)
{
	struct AdjList *p = graph->list;

	struct AdjListNode *adjNode = newAdjListNode(dest);
	struct AdjListNode *root = p->root[src];

	if(root==NULL)
	{

		p->root[src]=adjNode;

		return;
	}


	while(root->next!=NULL)
	{
		root=root->next;
	}
	
	root->next=adjNode;
	
}


int count_lines (FILE *file)
{
	int count=0;

	char line[1024];
	while(fgets(line,1024,file))
	{
		count++;
	}

	return count-1;
}


void printGraph(struct Graph *graph)
{
	struct AdjList *p = graph->list;

	struct AdjListNode** adjList = p->root;

	for(int i=0;i<graph->V;i++)
	{
		struct AdjListNode *root = adjList[i];
		
		if(root==NULL)
		{
			printf("\n %i. Sensorun komusu yok",i);
			continue;
			
		}

		printf("\n %d Idli sensorun komsularu: ",i);
		while(root)
		{
			printf("%d ",root->dest);
			root=root->next;
		}

		printf("\n");
	}
}

struct DynamicSensorArray* createSensorArr(int n)
{

	struct DynamicSensorArray* p = (struct DynamicSensorArray*)malloc(sizeof(struct DynamicSensorArray));
	p->len=0;
	p->size=2;
	p->arr = (struct Sensor *)malloc(sizeof(struct Sensor));

	return p;
	
}

int isArrayFull(struct DynamicSensorArray *p)
{
	if(p->len==p->size-1)
		return 1;
	else
		return 0;

}


void grow(struct DynamicSensorArray *p)
{
	p->arr = realloc(p->arr,p->size*2);
	p->size=p->size*2;
}

void push(struct DynamicSensorArray *p,struct Sensor s)
{
	if(isArrayFull(p))
	
		grow(p);
	
	p->arr[p->len]=s;
	
	p->len++;
}

void load_sensors(FILE *file)
{
	char buffer[1024];
	while(fgets(buffer,1024,file))
	{
		
		
		printf("\n %s",buffer);

	}

}

