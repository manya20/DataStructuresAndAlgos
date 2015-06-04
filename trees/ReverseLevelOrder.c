#include<stdio.h>
#include<stdlib.h>
struct BinaryTree
{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
};

typedef struct BinaryTree t;
struct Queue
{
	int size;
	int front,rear;
	t *arr[50];
};
struct Stack
{
	int top;
	t *arr2[50];
};
typedef struct Stack stack;

stack myStack;
void push(t*);
t* pop();
typedef struct Queue q;
q myQueue;
void Enqueue(t*);
t* Dequeue();
void printLevelOrder();
void printStack();
int size();
int isEmpty();
int isItEmpty();
main()
{	
	myStack.top=-1;
	myQueue.size=0;
	myQueue.front=-1;
	myQueue.rear=-1;
	t *root,*temp1,*temp2,*temp3;
	root=(t*)malloc(sizeof(t));
	temp1=root;
	temp1->data=1;
	temp1->left=(t*)malloc(sizeof(t));
	temp2=temp1->left;
	temp2->data=2;
	temp1->right=(t*)malloc(sizeof(t));
	temp3=temp1->right;
	temp3->data=3;
	temp2->right=NULL;
	temp2->left=(t*) malloc(sizeof(t));
	temp2=temp2->left;
	temp2->data=4;
	temp2->left=NULL;
	temp2->right=NULL;
	temp3->left=(t*)malloc(sizeof(t));
	temp2=temp3->left;
	temp2->data=5;
	temp2->left=NULL;
	temp2->right=NULL;
	temp3->right=(t*)malloc(sizeof(t));
	temp3=temp3->right;
	temp3->data=6;
	temp3->left=NULL;
	temp3->right=NULL;
	printf("sdfdsf");
	Enqueue(root);
	printLevelOrder();
}

int size()
{
	return myQueue.size;
}
void printLevelOrder()
{	

	while(!isEmpty())
	{	
		t *temp;
		int i=size();
		while(i>0)
		{
				temp=Dequeue();
				push(temp);
				if(temp->right)
				Enqueue(temp->right);
				if(temp->left)
				Enqueue(temp->left);
				i--;
		}
	}
	printStack();
}
int isEmpty()
{
	if(myQueue.front==-1)
	return 1;
	return 0;
}

void Enqueue(t *node)
{
	if(myQueue.front==-1)
	{
		myQueue.front++;
		myQueue.rear++;
		myQueue.size++;
		myQueue.arr[myQueue.front]=node;
		return;
	}
	else
	{
		myQueue.size++;
		myQueue.rear++;
		myQueue.arr[myQueue.rear]=node;
	}
	
}
t* Dequeue()
{	
	if(myQueue.rear==myQueue.front)
	{	
		int i=myQueue.front;
		myQueue.size=0;
		myQueue.front=-1;
		myQueue.rear=-1;
		return myQueue.arr[i];
	}
	else
	{
		myQueue.size--;
		return myQueue.arr[myQueue.front++];
	}
}
void push(t *node)
{
	myStack.top++;
	myStack.arr2[myStack.top]=node;
}
t* pop()
{
	return myStack.arr2[myStack.top--];
}
int isItEmpty()
{
	if(myStack.top==-1)
	return 1;
	else
	return 0;
}
void printStack()
{
	while(isItEmpty()!=1)
	{
		printf("\n%d",pop()->data);
	}
}
