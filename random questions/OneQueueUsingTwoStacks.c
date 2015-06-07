#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int top;
	int capacity;
	int arr[50];
};
typedef struct Stack st;

void push(st*,int);
int pop(st*);
int isEmpty(st*);
int isFull(st*);
main()
{	
	st *s1 = (st*) malloc(sizeof(st)),*s2 = (st*) malloc(sizeof(st));
	s1->capacity = s2->capacity = 50;
	s1->top = s2->top = -1;
	int i = 1;
	while(!isFull(s1))
		 push(s1,i++);
	//while(!isEmpty(s))
		//printf("%d ",pop(s));
	//printf("%d %d",pop(s),pop(s));
	//printf("%d %d",s->arr[49],s->arr[48]);
	printf("done\n");
	while(!isEmpty(s1))
	{
		printf("%d ",dequeue(s1,s2));
		//printf("returning....\n");	
	}

	
}

int isFull(st *s)
{
	if(s->top == s->capacity - 1)
	{
		//printf("Stack is full\n");
		return 1;
	}
	else
		return 0;
}

int isEmpty(st *s)
{
	if(s->top == -1)
	{
		//printf("Stack is Empty\n");
		return 1;
	}
	else
		return 0;
}

void push(st *s,int data)
{
	if(!isFull(s))
		s->arr[ ++s->top ] = data;
	else
		printf("Stack is full\n");
		
}

int pop(st *s)
{
	if(!isEmpty(s))
		return s->arr[ s->top-- ];
	else
		printf("Stack is Empty\n");

	return;
}

int dequeue(st *s1,st *s2)
{
	while(s1->top != 0)
	{
		push(s2,pop(s1));
		//printf("Shifting ..");
	}
	int num = s1->arr[s1->top--];
	while(!isEmpty(s2))
		push(s1,pop(s2));

	return num;
}





