#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct MyStructure
{
	int data;
	int key;
};

typedef struct MyStructure ms;

struct Heap
{
	ms arr[20];
	int capacity;
	int size;
};

typedef struct Heap heap;

void push(heap*,int,int);
void insert(heap*,int,int);
int pop(heap*);
int deleteMin(heap*);
int isFull(heap*);
int isEmpty(heap*);

main()
{
	heap *hp = (heap*) malloc(sizeof(heap));
	hp->capacity = 20;
	hp->size = 0;	
	int data,key = 0;
	srand(time(NULL));
	while(!isFull(hp))
	{	
		int i = rand() % 50;
		printf("%d ",i);
		push(hp,i,key--);
	}
	printf("fsdfd\n\n");
	int i = 0;
	//while(i < hp->size)
		//printf("%d\n",hp->arr[i++].data);
	while(!isEmpty(hp))
	printf("%d\n",pop(hp));
}


void push(heap *hp,int data,int key)
{
	insert(hp,data,key);
}



int pop(heap *hp)
{	
	int i = deleteMin(hp);
	return i;
}


int isFull(heap *hp)
{
	if(hp->size >= hp->capacity)
		return 1;
	else
		return 0;
}


int isEmpty(heap *hp)
{
	if(hp->size == 0)
		return 1;
	else
		return 0;
}


void insert(heap *hp,int data,int key)
{	
	if(!isFull(hp))
	{
	if(hp->size == 0)
	{
		hp->arr[0].data = data;
		hp->arr[0].key = key;
		hp->size++;
	}
	else
	{
		int i = hp->size++,child;
		while(i > 0 && hp->arr[(i - 1) / 2].key > key)
		{
			hp->arr[i].data = hp->arr[(i - 1) / 2].data;
			hp->arr[i].key = hp->arr[(i - 1) / 2].key;
			i = (i - 1) / 2; 
		}
		hp->arr[i].data = data;
		hp->arr[i].key = key;
		return ;
		
	}
	}
	else
	{
		printf("Heap is full");
	}
}

int deleteMin(heap *hp)
{	
	if(!isEmpty(hp))
	{
	int firstElement = hp->arr[0].data;
	int lastElement = hp->arr[hp->size - 1].data;
	hp->arr[0].data = hp->arr[hp->size - 1].data;
	hp->arr[0].key = hp->arr[hp->size - 1].key; 
	hp->size--;
	int i = 0;
	while( 2 * i + 1 < hp->size)
	{	
		if(hp->arr[i].key < hp->arr[2 * i + 1].key && hp->arr[i].key < hp->arr[2 * i + 2].key)
			break;
		
		else if(hp->arr[2 * i + 1].key < hp->arr[2 * i + 2].key)
		{	
			int temp_key = hp->arr[i].key;
			int temp_data = hp->arr[i].data;
			hp->arr[i].data = hp->arr[2 * i + 1].data;
			hp->arr[i].key = hp->arr[2 * i + 1].key;
			hp->arr[2 * i + 1].data = temp_data ;
			hp->arr[2 * i + 1].key = temp_key;
			i = 2 * i + 1;
		}
		else
		{	
			int temp_key = hp->arr[i].key;
			int temp_data = hp->arr[i].data;
			hp->arr[i].data = hp->arr[2 * i + 2].data;
			hp->arr[i].key = hp->arr[2 * i + 2].key;
			hp->arr[2 * i + 2].data = temp_data ;
			hp->arr[2 * i + 2].key = temp_key;
			i = 2 * i + 2;
		}
	}
	
	return firstElement;
	}
	else
	{
		printf("\nHeap is empty!!");
		return;
	}


}
