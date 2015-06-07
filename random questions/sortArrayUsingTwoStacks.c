#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int arr[20];
	int top;
	int capacity;
};
typedef struct Stack st;

void push(st*,int);
int pop(st*);
int isFull(st*);
int isEmpty(st*);
void sortArray(int arr[],int size,st *s1,st *s2);

main()
{
	st *s1 = (st*) malloc(sizeof(st)),*s2 = (st*) malloc(sizeof(st));
	s1->top = s2->top = -1;
	s1->capacity = s2->capacity = 20;
	int size = 0,data;
	int arr[20];
	while(1)
	{
		printf("Enter the number..\n");
		scanf("%d",&data);
		if(data == -1)
		break;
		else
		arr[size++] = data;
	}
	int i;
	printf("\n before delete\n");
	for(i = 0;i < size ; i++)
	printf("%d ",arr[i]);
	sortArray(arr,size,s1,s2);
	printf("\n after sorting\n");
	for(i = 0;i < size ; i++)
	printf("%d ",arr[i]);
}


void push(st *s,int data)
{
	if(isFull(s) == 0)
	{
		s->arr[++s->top] = data;
	}
	else
	printf("Stack is full");
}

int pop(st *s)
{
	
	if(isEmpty(s) == 0)
		return s->arr[s->top--];
	else
		printf("Stack is already empty!!");
	return -1;

}

int isFull(st *s)
{
	if(s->top == s->capacity - 1)
	return 1;
	else
	return 0;
}

int isEmpty(st* s)
{
	if(s->top == -1)
	return 1;
	else
	return 0;	
	
}

void sortArray(int arr[],int size,st *s1,st *s2)
{
	int i = 0;
	while(i < size)
	{
	
		if(s1->top == -1)
		{
			push(s1,arr[i]);
		}
		else
		{
			while(s1->arr[s1->top] < arr[i])
			{	
				if(s1->top == -1)
				break;
				int temp = pop(s1);
				push(s2,temp);
			}
			push(s1,arr[i]);
			while(isEmpty(s2) == 0)
			{
				int temp = pop(s2);
				push(s1,temp);
			}
		}
		i++;	

	}
	i = 0;
	while(!isEmpty(s1))
	arr[i++] = pop(s1);	
}





