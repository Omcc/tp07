#ifndef TP07
#define TP07

#include <stdio.h>


struct AdjListNode
{
	int dest;
	struct AdjListNode *next;
};


struct AdjList{

	struct AdjListNode **root;
};

struct Graph
{
	int V;
	struct AdjList *list;
};

struct Sensor{
	int x;
	int y;
	int z;
};

struct DynamicSensorArray{

	int len;
	int size;
	struct Sensor *arr;
};



struct AdjListNode* newAdjListNode(int dest);

struct Graph* createGraph(int V);

void addEdge(struct Graph *graph,int src,int dest);

void printGraph(struct Graph *graph);


struct DynamicSensorArray* createSensorArr(int n);




//utility functions

int count_lines(FILE *file);

#endif
