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

typedef struct Queue q;
q myQueue;
void Enqueue(t*);
t* Dequeue();
int size();
int isEmpty();
t* deepestNode(t*);
main()
{
		myQueue.size=0;
	myQueue.front=-1;
	myQueue.rear=-1;
	t *root,*temp1,*temp2,*temp3,*temp4;
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
	temp3->right=(t*)malloc(sizeof(t));
	temp2=temp3->right;
	temp2->left=(t*)malloc(sizeof(t));
	temp2->right=NULL;
	temp2->data=7;
	temp2=temp2->left;
	temp2->left=NULL;
	temp2->right=NULL;
	temp2->data=11;
	temp4=deepestNode(root);
	printf("The deepest node is %d",temp4->data);
}
int size()
{
	return myQueue.size;
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
t* deepestNode(t *root)
{
	
	Enqueue(root);
	t *temp;
	while(!isEmpty())
	{	
		
		int i=size();
		while(i>0)
		{
				temp=Dequeue();
				printf("%d\n",temp->data);
				if(temp->left)
				Enqueue(temp->left);
				if(temp->right)
				Enqueue(temp->right);
				i--;
		}
		
	}
	return temp;
}
