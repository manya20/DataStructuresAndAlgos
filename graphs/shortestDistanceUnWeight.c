#include<stdio.h>
#include<stdio.h>

struct Node
{
	int vNum;
	struct Node *next;
};

typedef struct Node node;


struct Graph
{
	int V;
	int E;
	node *list;
};

typedef struct Graph graph;

struct Table
{
	int *vertexCol,*distanceCol;
};

typedef struct Table table;
struct Queue
{
	int size;
	int front,rear;
	node *arr[50];
};

typedef struct Queue q;
q myQueue;
void Enqueue(node*);
node* Dequeue();

void shortestDistance(graph *g,table *t,int sourceVertex);

void topSort(graph *g,int inDeg[],int topOrder[]);
void insert(graph *g,int u,int v);
void init(graph *g);
main()
{
	int i,u,v,sourceVertex;
	myQueue.front = myQueue.rear = -1;
	myQueue.size = 0;
	graph *g = (graph*)malloc(sizeof(graph));
	printf("Enter the number of Vertexes\n");
	scanf("%d",&g->V);
	printf("Enter the number of edges");
	scanf("%d",&g->E);
	g->list = (node*)malloc(sizeof(node) * g->V);
	init(g);
	table *t = (table*)malloc(sizeof(table));
	t->vertexCol = (int *)malloc(sizeof(int) * g->V);
	t->distanceCol = (int *)malloc(sizeof(int) * g->V);
	for(i = 0;i < g->V;i++)
	{
		t->vertexCol[i] = i;
		t->distanceCol[i] = -1;
	}
	printf("Enter an edges.....u-v\n");
	for(i = 0;i < g->E;i++)
	{
		scanf("%d %d",&u,&v);
		insert(g,u,v);
	}
	
	printf("done inserting\n");
	printf("Enter the source vertex\n");
	scanf("%d",&sourceVertex);
	shortestDistance(g,t,sourceVertex);
	
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
	for(i = 0 ;i < g->V;i++)
		printf("%d ",t->distanceCol[i]);
	printf("\n");
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


int size()
{
	return myQueue.size;
}

int isEmpty()
{
	if(myQueue.front==-1)
	return 1;
	return 0;
}

void Enqueue(node *n)
{
	if(myQueue.front==-1)
	{
		myQueue.front++;
		myQueue.rear++;
		myQueue.size++;
		myQueue.arr[myQueue.front]=n;
		return;
	}
	else
	{
		myQueue.size++;
		myQueue.rear++;
		myQueue.arr[myQueue.rear]=n;
	}
	
}
node* Dequeue()
{	
	if(myQueue.rear==myQueue.front)
	{	
		int i=myQueue.front;
		myQueue.size=0;
		myQueue.front=-1;
		myQueue.rear=-1;
		return myQueue.arr[i];
	}
	else
	{
		myQueue.size--;
		return myQueue.arr[myQueue.front++];
	}
}

void shortestDistance(graph *g,table *t,int sourceVertex)
{
	t->distanceCol[sourceVertex] = 0;
	Enqueue(g->list + sourceVertex);
	node *temp,*w;
	while(!isEmpty())
	{
		temp = Dequeue();
		w = (g->list + temp->vNum)->next;
		while(w)
		{
			int vNum = w->vNum;
			if(t->distanceCol[vNum] == -1)
			{
				t->distanceCol[vNum] = t->distanceCol[temp->vNum] + 1;
				
				Enqueue(w);
				printf("Enqueued %d node \n",w->vNum);
			}
			w = w->next;
		}
	}
}
