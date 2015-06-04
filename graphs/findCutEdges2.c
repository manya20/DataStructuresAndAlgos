#include<stdio.h>
#include<stdio.h>

struct Node
{
	int vNum;
	struct Node *next;
	int cost;
};

typedef struct Node node;


struct Graph
{
	int V;
	int E;
	node *list;
};

typedef struct Graph graph;

struct Arrays
{
	int *dfsNum,*parent,*visited;
};

typedef struct Arrays arrays;

int counter = 0;
void insert(graph *g,int u,int v);
void init(graph *g);
void initializeArrays(graph *g,arrays *a);
void setdfsNum(graph *g,arrays *a,node *n);
int minimum(int a,int b);
int findCutEdges(graph *g,arrays *a,node *n);
main()
{
	int i,u,v,cost,source;
	node *temp;
	graph *g = (graph*)malloc(sizeof(graph));
	printf("Enter the number of Vertexes\n");
	scanf("%d",&g->V);
	printf("Enter the number of edges");
	scanf("%d",&g->E);
	g->list = (node*)malloc(sizeof(node) * g->V);
	init(g);
	arrays *a = (arrays*) malloc(sizeof(arrays));
	initializeArrays(g,a);
	printf("Enter an edges.....u-v\n");
	for(i = 0;i < g->E;i++)
	{
		
		scanf("%d%d",&u,&v);
		insert(g,u,v);
	}

	for(i = 0;i < g->V;i++)
	{
		node *temp = (g->list + i)->next;
		printf("The vertex %d has adjacent vertexes:",i);
		while(temp)
		{
			printf("%d->",temp->vNum);
			temp = temp->next;
		}
		printf("Null\n");
	}
	printf("\n\n\n");
	printf("Enter the number of source node for articulation check\n");
	scanf("%d",&source);
	
	setdfsNum(g,a,g->list + source);
	for(i = 0 ; i < g->V;i++)
		a->visited[i] = 0;
	//printf("parent of 6 is %d\n",a->parent[6]);	

	for(i = 0; i < g-> V ; i++)
	{
		printf("dfsNum of %dth is %d\n",i,a->dfsNum[i]);
		printf("parent of %dth is %d\n",i,a->parent[i]);
	}
	findCutEdges(g,a,g->list + source);
}

void insert(graph *g,int u,int v)
{
	
	int i,j;
	node *temp1,*temp2;
	temp1 = (node*)malloc(sizeof(node));
	temp1->vNum = v;
	temp2 = (g->list + u)->next;
	(g->list + u)->next = temp1;
	temp1->next = temp2;

	temp1 = (node*)malloc(sizeof(node));
	temp1->vNum = u;
	temp2 = (g->list + v)->next;
	(g->list + v)->next = temp1;
	temp1->next = temp2;
	
	//printf("inserted\n");

}

void init(graph *g)
{
	int i;
	for(i = 0;i < g->V;i++)
	{
		(g->list + i)->vNum = i;		
		(g->list + i)->next = NULL;
	}
}

void initializeArrays(graph *g,arrays *a)
{
	a->visited = (int *) malloc(sizeof(int) * g->V);
	a->dfsNum = (int *) malloc(sizeof(int) * g->V);
	a->parent = (int *) malloc(sizeof(int) * g->V);
	int i;
	for(i = 0 ; i < g->V; i++)
	{
		a->visited[i] = 0;	
	}
}

void setdfsNum(graph *g,arrays *a,node *n)
{
	a->dfsNum[n->vNum] = counter++;
	a->visited[n->vNum] = 1;
	printf("%dth vertex visited\n",n->vNum);
	node *w = (g->list + n->vNum)->next;
	while(w)
	{
		if(a->visited[w->vNum] == 0)
		{
			a->parent[w->vNum] = n->vNum;
			setdfsNum(g,a,w);
		}
		w = w->next;
	}
}





int minimum(int a,int b)
{
	if(a > b)
		return b;
	else
		return a;
}

int findCutEdges(graph *g,arrays *a,node *n)
{
	int deepestNode = a->dfsNum[n->vNum],temp;
	a->visited[n->vNum] = 1;
	node *w = (g->list + n->vNum)->next;
	//printf("outside loop\n");
	while(w)
	{
		//printf("inside loop.. processing %dth vertex.\n",n->vNum);
		if(a->dfsNum[w->vNum] > a->dfsNum[n->vNum])
		{
			if(a->visited[w->vNum] == 0)
			{
				temp = findCutEdges(g,a,w);
				if(temp < deepestNode)
					deepestNode = temp;
				
			}
			
		}
		else
		{
			if(a->parent[n->vNum] != w->vNum)
			{
				if(a->dfsNum[w->vNum] <= deepestNode)
					deepestNode =  a->dfsNum[w->vNum];
			}
		}
		w = w->next;
	}

	if(deepestNode >= a->dfsNum[n->vNum] && a->parent[n->vNum] != 0) //the second part of the condition is to take the root vertex into  
									 //root vertex into consideration.if its not written. theN one extra
									 //edge connected to root that may or may not be in the dfs tree will
									 // come as cut edge.
	{
		printf("%d-%d is cut edge\n",n->vNum,a->parent[n->vNum]);
	}
			return deepestNode;
			
}

