#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int size;
	int *arr;
	int top;
};

typedef struct Stack stack;

void init(stack *st,int size);
int isFull(stack *st);
int isEmpty(stack *st);
void push(stack *st,int data);
int pop(stack *st);
void reverseTheStack(stack *st,stack *aux,int size);
main()
{
	stack *st = (stack*) malloc(sizeof(stack));
	stack *aux = (stack*) malloc(sizeof(stack));
	int size,data;
	printf("Enter the input size\n");
	scanf("%d",&size);
	init(st,size);
	init(aux,size);
	printf("stack size = %d top = %d\n",st->size,st->top);
	printf("Enter the elements..\n");
	int i = 0;
	while(i++ < size)
	{
		scanf("%d",&data);
		push(st,data);
	}
	printf("done pushing\n");
	reverseTheStack(st,aux,size);
	while(!isEmpty(st))
	{
		printf("%d ",pop(st));
	}
	printf("\n");
	
}


void init(stack *st,int size)
{
	st->top = -1;
	st->size = size;
	st->arr = (int*)malloc(sizeof(int) * (st->size));
}

int isFull(stack *st)
{
	if(st->top == st->size - 1)
		return 1;
	else return 0;
}

int isEmpty(stack *st)
{
	if(st->top == -1)
		return 1;
	else
		return 0;
}

void push(stack *st,int data)
{
	if(!isFull(st))
	{
		st->arr[++st->top] = data;
	}
	else
	{
		printf("Stack is full\n");
	}
	return;
}

int pop(stack *st)
{
	if(!isEmpty(st))
	{
		return st->arr[st->top--];
	}
	return;
}

void reverseTheStack(stack *st,stack *aux,int size)
{
	int i = 0;
	while(i < size - 1 )
	{
		int temp = pop(st);
		while(i != st->top + 1)
		{
			push(aux,pop(st));
		}
		push(st,temp);
		while(!isEmpty(aux))
		{
			push(st,pop(aux));
		}
		i++;
	}
}

























