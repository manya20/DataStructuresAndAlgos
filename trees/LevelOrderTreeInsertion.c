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
t* insertion(t* root,int data);
int size();
int isEmpty();
void deleteQueue();
void preorder(t* node);
main()
{	
	myQueue.front=myQueue.rear=-1;
	t *root=NULL;
	int data;
	while(1)
	{
		printf("Enter the numbers\n");
		scanf("%d\n",&data);
		if(data == -1)
		break;
		else
		root=insertion(root,data);
	}
	preorder(root);
}

t* insertion(t *root,int data)
{	
	t *temp=root;
	if(root == NULL)
	{
		root=(t*)malloc(sizeof(t));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else
	{
		
		Enqueue(root);
		while(1)
		{
			temp = Dequeue();
			if(temp->left && temp->right)
			{
				Enqueue(temp->left);
				Enqueue(temp->right);
			}
			else if(temp->left == NULL && temp->right!=NULL)
			{
				temp->left=(t*)malloc(sizeof(t));
				temp=temp->left;
				temp->data=data;
				temp->left=NULL;
				temp->right=NULL;
				deleteQueue();
				return root;
			}
			else if(temp->left!=NULL && temp->right==NULL)
			{
				temp->right=(t*)malloc(sizeof(t));
				temp=temp->right;
				temp->data=data;
				temp->left=NULL;
				temp->right=NULL;
				deleteQueue();
				return root;
			}
			else
			{
				temp->left=(t*)malloc(sizeof(t));
				temp=temp->left;
				temp->data=data;
				temp->left=NULL;
				temp->right=NULL;
				deleteQueue();
				return root;
			}
		}
	}
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
void deleteQueue()
{
	myQueue.front = myQueue.rear = -1;
}

void preorder(t* node)
{
	if(node == NULL)
	return;
	else
	{
		printf("%d\n",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

