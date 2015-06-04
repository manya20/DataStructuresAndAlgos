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
void InsertionUsingLevelOrder(int num);
main()
{
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
	(!isEmpty()?printf("the queue is not empty"):printf("queue is empty"));
		Enqueue(root);
	InsertionUsingLevelOrder(7);
	printf("\n\n\n");
	emptyTheQueue();
	Enqueue(root);
	printLevelOrder();
	Enqueue(root);
		InsertionUsingLevelOrder(10);
	printf("\n\n\n");
	emptyTheQueue();
	Enqueue(root);
	printLevelOrder();
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
void InsertionUsingLevelOrder(int num)
{	
	int i;
	t *temp,*temp2;
	while(!isEmpty())
	{
		i=size();
		while(i>0)
		{
			temp=Dequeue();
			if(temp->left==NULL)
			{
				temp2=(t*)malloc(sizeof(t));
				//temp->left->left=NULL;
				temp->left=temp2;
				//temp->left->right=NULL;
				temp2->left=NULL;
				temp2->right=NULL;
				temp2->data=num;
				return;
			}
			else if(temp->right==NULL)
			{
				temp2=(t*)malloc(sizeof(t));
				temp->right=temp2;
				temp2->left=NULL;
				temp2->right=NULL;
				temp2->data=num;
				return;
			}
			else
			{
				Enqueue(temp->left);
				Enqueue(temp->right);
				i--;
			}
		}
	}
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
				printf("%d\n",temp->data);
				if(temp->left)
				Enqueue(temp->left);
				if(temp->right)
				Enqueue(temp->right);
				i--;
		}
	}
}
void emptyTheQueue()
{
	myQueue.size=0;
	myQueue.front=-1;
	myQueue.rear=-1;
}
