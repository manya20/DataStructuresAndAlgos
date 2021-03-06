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
main()
{
	stack *st = (stack*) malloc(sizeof(stack));
	int size,data;
	printf("Enter the max size of Stack\n");
	scanf("%d",&size);
	init(st,size);
	printf("stack size = %d top = %d\n",st->size,st->top);
	printf("Enter the elements.. press -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else if(isFull(st))
		{
			printf("Stack is full.. cant enter more data\n");
			break;
		}
		else
		push(st,data);
	}
	while(!isEmpty(st))
		printf("%d ",pop(st));
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

