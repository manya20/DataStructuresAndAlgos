#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack
{
	int size;
	char *arr;
	int top;
};

typedef struct Stack stack;
void init(stack *st,int size);
int isFull(stack *st);
int isEmpty(stack *st);
void push(stack *st,char data);
char pop(stack *st);
void check(stack *st,char arr[],int size);

main()
{
	stack *st = (stack*) malloc(sizeof(stack));
	int i,size = 0;
	char data;
	printf("Enter the max size of input\n");
	scanf("%d",&size);
	init(st,size);
	char arr[size];
	printf("Enter  input parenthesis..only enter parenthesis.. else prog wont work. press anything else to exit\n");
	size = 0;
	while(1)
	{
		
		scanf(" %c",&data);
		if(data == '(' || data == ')')
		{
			arr[size++] = data;
		}
		else
			break;
	}
	check(st,arr,size);
}


void init(stack *st,int size)
{
	st->top = -1;
	st->size = size;
	st->arr = (char*)malloc(sizeof(char) * (st->size));
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

void push(stack *st,char data)
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



char pop(stack *st)
{
	if(!isEmpty(st))
	{
		return st->arr[st->top--];
	}
	return '\0';
}

void check(stack *st,char arr[],int size)
{
	int i = 0;
	while(i < size)
	{
		if(arr[i] == '(')
			push(st,arr[i]);
		else
		{
			char ch = pop(st);
			if(ch != '(')
			{
				printf("not balanced\n");
				return;
			}
		}		
		i++;	
	}
	if(isEmpty(st))
		printf("balanced\n");	
	else
		printf("not balanced\n");
}

