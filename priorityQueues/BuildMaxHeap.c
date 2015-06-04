#include<stdio.h>
#include<stdlib.h>

struct Priority_Queue
{
	int size,max;
	int arr[50];
};

typedef struct Priority_Queue heap;

void buildHeap(heap *hp,int size);
void percDown(heap *hp,int i);
int larger(heap *hp,int, int);
void swap(heap *hp,int,int);

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
		hp->arr[i++] = data;
		hp->size++;
	}
	printf("Before Heap is created\n");
	for(j = 0;j < i;j++)
		printf("%d ",hp->arr[j]);
	printf("\n");
	buildHeap(hp,i);
	printf("After the Heap is created\n");
	for(j = 0;j < i;j++)
		printf("%d ",hp->arr[j]);
	printf("\n");
	

}

void buildHeap(heap *hp,int size)
{
	int i;
	for(i = (size / 2 ) - 1;i >= 0;i--)
	{
		//printf("i = %d\n",i);
		percDown(hp,i);
	}
}

void percDown(heap *hp,int i)
{
	
	while(i >= 0)
	{
		if(2*i + 2 <= hp->size - 1)
		{
			//printf("inside first condition\n");
			if(hp->arr[i] >= hp->arr[2*i + 1] && hp->arr[i] >= hp->arr[2 * i + 2 ])
				break;
			else
			{
				int index = larger(hp,2 * i + 1,2 * i + 2);
				//printf("%d is larger ",hp->arr[index]);
				swap(hp,i,index);
				i = i / 2;
			}
			
		}
		else
		{
			if(hp->arr[i] >= hp->arr[2*i + 1])
				break;
			else
			{
				swap(hp,i,2 * i + 1);
				 i = i / 2;
			}
		}
	}

}


int larger(heap *hp,int i,int j)
{
	if(hp->arr[i] >= hp->arr[j])
		return i;
	else
		return j;
}

void swap(heap *hp,int i,int j)
{
	int temp = hp->arr[i];
	hp->arr[i] = hp->arr[j];
	hp->arr[j] = temp;	
}
