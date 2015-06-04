#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct priorityqueue
{
	int arr[50];
	int size;
	int capacity;
};
typedef struct priorityqueue heap;

void insert(heap*,int);
void printSmallerThanK(heap *hp,int i,int k);

main()
{
	heap hp;
	hp.size = 0;
	hp.capacity = 10;
	int data,i;
	srand(time(NULL));
	i = 0;
	while(i++ < hp.capacity)
		insert(&hp,rand() % 10);
	
	printf("before delete\n");
	for(i = 0;i < hp.size;i++)
	{
		printf("%d ",hp.arr[i]);
	}
	printf("Enter K..\n");
	scanf("%d",&data);
	printSmallerThanK(&hp,0,data);
}


void insert(heap *hp,int data)
{
	if(hp->size == 0)
	
	{
		hp->arr[0] = data;
		hp->size++;
		return;
	}
	else{
	
		int i = hp->size;
		while(i > 0 && hp->arr[(i - 1) / 2] >= data){
			hp->arr[i] = hp->arr[(i - 1) / 2];
			i = (i - 1) / 2;		
		}
		hp->arr[i] = data;
		hp->size++;
		return;
		

	}
}

void printSmallerThanK(heap *hp,int i,int k)
{
	
	if(hp->arr[i] <= k)
		printf("%d ",hp->arr[i]);
	if(2 * i + 1 >= hp->size)
		return;
	else
	{
		printSmallerThanK(hp,2 * i + 1,k);
		printSmallerThanK(hp,2 * i + 2,k);
	}
	
}
