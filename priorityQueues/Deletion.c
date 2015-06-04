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
void delete(heap *hp);
int smaller(heap *hp,int i,int j);
main()
{
	int data,i,j,temp;
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
			hp->size++;
		}
	}
	printf("here\n");
	temp = hp->size;
	for(i = 0;i < temp;i++)
		delete(hp);
	//for(i = 0;i < hp->size;i++)
	//	printf("%d ",hp->arr[i]);

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
}

void swap(heap *hp,int i,int j)
{
	int temp = hp->arr[i];
	hp->arr[i] = hp->arr[j];
	hp->arr[j] = temp;	
}

void delete(heap *hp)
{
	printf("%d ",hp->arr[0]);
	hp->arr[0] = hp->arr[hp->size - 1];
	hp->size--;
	int i = 0,index;
	while(1)
	{
		if(2 * i + 2 < hp->size)
		{
			if(hp->arr[i] <= hp->arr[2 * i + 1] && hp->arr[i] <= hp->arr[2 * i + 2])
				break;
			else
			{
				index = smaller(hp,2 * i + 1,2 * i + 2);
				swap(hp,i,index);
				i = index;
			}	
		}
		else if(2 * i + 2 == hp->size)
		{
			if(hp->arr[i] <= hp->arr[2 * i + 1])
				break;
			else
			{
				swap(hp,i,2 * i + 1);
				i = 2 * i + 1;
			}
		}
		else
		{
			break;
		}
	}
	/*printf("\n");
	for(i = 0 ;i < hp->size;i++)
		printf("%d ",hp->arr[i]);
	printf("\n");*/	 
}


int smaller(heap *hp,int i,int j)
{
	if(hp->arr[i] <= hp->arr[j])
		return i;
	else
		return j;
}

