#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int front,rear;
	int arr[50];
	int capacity;
};

typedef struct Queue q;
void enqueue(q*,int);
int dequeue(q*);
int isFull(q*);
int isEmpty(q*);
int pop(q* q1,q *q2);

main()
{
	q *q1 =(q*)malloc(sizeof(q)),*q2 = (q*)malloc(sizeof(q));
	q1->capacity = q2->capacity = 20;
	q1->front = q1->rear = q2->front = q2->rear = -1;
	int i,data;
	i=0;
	while(!isFull(q1))
	{
		enqueue(q1,i);
		i++;
	}
	
	while(!isEmpty(q1))
	{
		printf("%d ",pop(q1,q2));
	}

}

int isFull(q* qu)
{
	if(qu->rear == qu->capacity - 1)
		return 1;
	else
		return 0;
}
int isEmpty(q* qu)
{
	if(qu->front == -1)
		return 1;
	else
		return 0;
}

void enqueue(q *qu,int data)
{
	if(!isFull(qu))
	{
		if(qu->front == -1)
		{
			qu->front++;
			qu->rear++;
			qu->arr[qu->rear] = data;
		}
		else
		{
			qu->arr[++qu->rear] = data;
		}
	}
	else
	{
		printf("Queue is full");
	}

}

int dequeue(q *qu)
{	
	int num = -1;
	if(!isEmpty(qu))
	{
		if(qu->front == qu->rear)
		{	
			int num = qu->arr[qu->front];
			qu->front = qu->rear = -1;
			return num;
			
		}
		else
		{
			num = qu->arr[qu->front++];
			return num;
			
		}
	}
	else
	{
		printf("Stack is already empty");
		return ;
	}
	return ;
}

int pop(q* q1,q *q2)
{
	while(!isEmpty(q1))
		enqueue(q2,dequeue(q1));
	while(q2->front != q2->rear )
		enqueue(q1,dequeue(q2));
	return dequeue(q2);
}





