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
void topSort(graph *g,int inDeg[],int topOrder[]);
void insert(graph *g,int u,int v);
void init(graph *g);
main()
{
	int i,u,v,inDeg[15],topOrder[15];
	myQueue.front = myQueue.rear = -1;
	myQueue.size = 0;
	graph *g = (graph*)malloc(sizeof(graph));
	printf("Enter the number of Vertexes\n");
	scanf("%d",&g->V);
	printf("Enter the number of edges");
	scanf("%d",&g->E);
	g->list = (node*)malloc(sizeof(node) * g->V);
	init(g);
	printf("Enter an edges.....u-v\n");
	for(i = 0;i < g->E;i++)
	{
		scanf("%d %d",&u,&v);
		insert(g,u,v);
	}
	
	printf("done inserting\n");
	for(i = 0;i < g->V;i++)
	{
		inDeg[i] = 0;
	}
	for(i = 0 ; i < g->V;i++)
	{
		node *temp = g->list + i;
		temp = temp->next;
		while(temp)
		{
			inDeg[temp->vNum]++;
			temp = temp->next;
		}
	}	
	topSort(g,inDeg,topOrder);

	for(i = 0;i < g->V;i++)
	{
		printf("%d ",topOrder[i]);
	}		
	printf("\n");

	/*for(i = 0;i < g->V;i++)
	{
		node *temp = (g->list + i)->next;
		printf("The vertex %d has adjacent vertexes:",i);
		while(temp)
		{
			printf("%d->",temp->vNum);
			temp = temp->next;
		}
		printf("Null\n");
	}*/
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

void topSort(graph *g,int inDeg[],int topOrder[])
{
	
	int i,j,index = 0;
	for(i = 0;i < g->V;i++)
	{
		if(inDeg[i] == 0)
			Enqueue(g->list + i);
	}
	
	while(!isEmpty())
	{
		
		node *temp = Dequeue();
		topOrder[index++] = temp->vNum;
		temp = temp->next;
		while(temp)
		{
			
			inDeg[temp->vNum]--;
			if(inDeg[temp->vNum] == 0)
				Enqueue(g->list + temp->vNum);
			temp = temp->next;
		}
	}
	
}
