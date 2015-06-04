#include<stdio.h>
#include<stdio.h>

struct Node
{
	int vNum,cost;
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
	int *vertexCol,*distanceCol,*path,*known;
};

typedef struct Table table;

struct PriorityQueue
{
	int size;
	node *arr[20];
};

typedef struct PriorityQueue heap;
void insert(graph *g,int u,int v,int cost);
void insertInMinHeap(table *t,heap *hp,node *n);
void init(graph *g);
void swap(heap *hp,int i,int j);
int isEmpty(heap *hp);
void prim(graph *g,table *t,heap *hp,int sourceVertex);
void updateHeap(table *t,heap *hp,node *n);
node *delete(table *t,heap *hp);
int smaller(table *t,heap *hp,int i,int j);
main()
{
	int i,u,v,sourceVertex,cost;
	heap *hp = (heap*) malloc(sizeof(heap));
	hp->size = 0;
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
	t->path = (int *)malloc(sizeof(int) * g->V);
	t->known = (int *)malloc(sizeof(int) * g->V);
	for(i = 0;i < g->V;i++)
	{
		t->vertexCol[i] = i;
		t->distanceCol[i] = -1;
		t->path[i] = -1;
		t->known[i] = -1;
	}
	printf("Enter an edges and its cost.....u-v\n");
	for(i = 0;i < g->E;i++)
	{
		scanf("%d %d %d",&u,&v,&cost);
		insert(g,u,v,cost);
	}
	
	printf("done inserting\n");
	printf("Enter the source vertex\n");
	scanf("%d",&sourceVertex);
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
	prim(g,t,hp,sourceVertex);
	
	for(i = 0 ;i < g->V;i++)
		printf("%d ",t->distanceCol[i]);
	printf("\n");
}

void insert(graph *g,int u,int v,int cost)
{
	
	int i,j;
	node *temp1,*temp2;
	temp1 = (node*)malloc(sizeof(node));
	temp1->vNum = v;
	temp1->cost = cost;
	temp2 = (g->list + u)->next;
	(g->list + u)->next = temp1;
	temp1->next = temp2;

	temp1 = (node*)malloc(sizeof(node));
	temp1->vNum = u;
	temp1->cost = cost;
	temp2 = (g->list + v)->next;
	(g->list + v)->next = temp1;
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

void prim(graph *g,table *t,heap *hp,int sourceVertex)
{
	t->distanceCol[sourceVertex] = 0;
	t->path[sourceVertex] = sourceVertex; // this 2 values shows the sourceVertex is the starting point
	node *temp,*w;
	insertInMinHeap(t,hp,g->list + sourceVertex);
	while(!isEmpty(hp))
	{
		temp = delete(t,hp);
		t->known[temp->vNum] = 1;
		int newDistance;
		printf("vertex %dth is selected \n",temp->vNum);
		w = (g->list + temp->vNum)->next;
		while(w)
		{
			newDistance = w->cost;
			if(t->distanceCol[w->vNum] == -1)
			{
				t->distanceCol[w->vNum] = newDistance;
				t->path[w->vNum] = temp->vNum;
				insertInMinHeap(t,hp,w);
			}
			if(t->distanceCol[w->vNum] > newDistance && t->known[w->vNum] == -1)
			{
				t->distanceCol[w->vNum] = newDistance;
				t->path[w->vNum] = temp->vNum;
				updateHeap(t,hp,w);
			}
			printf("%dth cost is %d\n",w->vNum,t->distanceCol[w->vNum]);
			w = w->next;
		}
	}	
}


void insertInMinHeap(table *t,heap *hp,node *n)
{
	hp->arr[hp->size] = n;
	int i = hp->size;
	int nodeVertexNum = n->vNum; 
	while( (i - 1) / 2 >= 0)
	{
		int parentVertexNum = hp->arr[(i - 1) / 2]->vNum;
		//printf("here\n");
		if(t->distanceCol[parentVertexNum] <= t->distanceCol[nodeVertexNum])
		{
			//printf("inside if of insertinmin\n");
			break;
		}
		else
		{
			swap(hp,(i - 1) / 2,i);
			i = (i - 1) / 2;
		}
		
	}
	hp->size++;
	//printf("below  %d",hp->size);
	//printf("inseted..size = %d\n",hp->size);
}


void swap(heap *hp,int i,int j)
{
	node *temp = hp->arr[i];
	hp->arr[i] = hp->arr[j];
	hp->arr[j] = temp;	
}



int isEmpty(heap *hp)
{
	if(hp->size == 0)
		return 1;
	else
		return 0;
}

void updateHeap(table *t,heap *hp,node *n)
{
	int i;
	for(i = 0;i < hp->size ; i++)
		if(hp->arr[i]->vNum == n->vNum)
			break;
	
	int nodeVertexNum = n->vNum; 
	while( (i - 1) / 2 >= 0 && i != 0)
	{
		int parentVertexNum = hp->arr[(i - 1) / 2]->vNum;
		printf("in update heap\n");
		if(t->distanceCol[parentVertexNum] <= t->distanceCol[nodeVertexNum])
			break;
		else
		{
			swap(hp,(i - 1) / 2,i);
			i = (i - 1) / 2;
		}
		
	}
}

node* delete(table *t,heap *hp)
{
	
	node *toReturn = hp->arr[0],temp;
	hp->arr[0] = hp->arr[hp->size - 1];
	hp->size--;
	int i = 0,parentVertexNum = hp->arr[0]->vNum,leftChildVertexNum,rightChildVertexNum,index;
	while(1)
	{
		if(2 * i + 2 < hp->size)
		{
			leftChildVertexNum = hp->arr[2 * i + 1]->vNum;
			rightChildVertexNum = hp->arr[2 * i + 2]->vNum;
			if(t->distanceCol[parentVertexNum] <= t->distanceCol[leftChildVertexNum] && t->distanceCol[parentVertexNum] <= 				t->distanceCol[rightChildVertexNum])
			{
				break;
			}
			else
			{
				index = smaller(t,hp,2 * i + 1,2 * i + 2);
				swap(hp,i,index);
				i = index;
			}
		} 

		else if(2 * i + 1 == hp->size)
		{
			leftChildVertexNum = hp->arr[2 * i + 1]->vNum;
			if(t->distanceCol[parentVertexNum] <= t->distanceCol[leftChildVertexNum])
				break;
			else
			{
				swap(hp,i,2 * i + 1);
				i = 2 * i + 1;
			}
		}
		else
			break;
	}
	return toReturn;
}

int smaller(table *t,heap *hp,int i,int j)
{
	int leftChildVertexNum = hp->arr[i]->vNum, rightChildVertexNum = hp->arr[j]->vNum;
	if(t->distanceCol[i] <= t->distanceCol[j])
		return i;
	else
		return j;
}
