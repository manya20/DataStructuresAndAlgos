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

void insert(graph *g,int u,int v);
void init(graph *g);
void depthFirst(graph *g,node *n,int known[]);
main()
{
	int i,u,v,cost,*known;
	graph *g = (graph*)malloc(sizeof(graph));
	printf("Enter the number of Vertexes\n");
	scanf("%d",&g->V);
	printf("Enter the number of edges");
	scanf("%d",&g->E);
	g->list = (node*)malloc(sizeof(node) * g->V);
	known = (int*) malloc(sizeof(int) * g->V);
	init(g);
	for(i = 0;i < g->V;i++)
	{
		known[i] = 0;
	}
	
	
	for(i = 0;i < g->E;i++)
	{
		printf("Enter an edges.....u-v\n");
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
	depthFirst(g,g->list,known);
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

void depthFirst(graph *g,node *n,int known[])
{
	known[n->vNum] = 1;
	printf("%d\n",n->vNum);
	node *w = (g->list + n->vNum)->next;
	while(w)
	{
		//printf("in if\n");
		if(known[w->vNum] == 0)
			depthFirst(g,w,known);

		w = w->next;
	}	
}


























