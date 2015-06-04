#include<stdio.h>
#include<stdlib.h>

struct Priority_Queue
{
	int size,max;
	int arr[50];
};

typedef struct Priority_Queue heap;

void insert(heap *hp,int data);
void swap(heap *hp,int i,int j);
main()
{
	int data,i,j;
	heap *hp = (heap*) malloc(sizeof(heap));
	hp->max = 50;
	hp->size = 0;
	printf("Enter the numbers and enter -1 to exit\n");
	i = 0;
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
		break;
		else
		{
			insert(hp,data);
			
		}
	}
	printf("here\n");
	for(i = 0;i < hp->size ;i++)
		printf("%d ",hp->arr[i]);
	printf("\n");
}

void insert(heap *hp,int data)
{
	hp->arr[hp->size] = data;
	int i = hp->size;
	while( (i - 1) / 2 >= 0)
	{	
		
		{
		if(hp->arr[(i - 1 )/ 2] <= hp->arr[i])
			break;
		else
		{
			swap(hp,(i - 1) / 2,i);
			i = (i - 1) / 2;
		}
		}
	}
	hp->size++;
}

void swap(heap *hp,int i,int j)
{
	int temp = hp->arr[i];
	hp->arr[i] = hp->arr[j];
	hp->arr[j] = temp;	
}
