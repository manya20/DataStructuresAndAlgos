#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};

typedef struct BST bst;
struct Stack
{
	int top;
	bst *arr[50];
};
typedef struct Stack st;

struct Stack myStack;

struct Queue
{
	int size;
	int front,rear;
	bst *arr[50];
};


typedef struct Queue q;
q myQueue;
void Enqueue(bst*);
bst* Dequeue();
void push(bst *node);
bst* pop();
int isStackEmpty();
bst* insert(bst*,int);
void inorder(bst*);
void printInLevelReverse(bst *root);

main()
{
	bst *root = NULL;
	int data;
	myStack.top = -1;
	while(1)
	{
		printf("Enter the number to insert in bst and -1 to exit\n");
		scanf("%d",&data);
		if(data == -1)
		break;
		root = insert(root,data);
	}
	//inorder(root);
	//printInLevelReverse(root);
	Enqueue(root);
	bst *temp = Dequeue();
	printf("\n\n%d",temp->data);
}

bst* insert(bst *root,int data)
{
	bst *temp=root;
	if(root == NULL)
	{	
		root=(bst*)malloc(sizeof(bst));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else{
		while(1)
		{
			//printf("ere\n");
			if(data < temp->data && temp->left!=NULL)
			temp=temp->left;
			else if(data <= temp->data && temp->left==NULL)
			{
				temp->left=(bst*)malloc(sizeof(bst));
				temp=temp->left;
				temp->data=data;
				temp->left=NULL;
				temp->right=NULL;
				
				return root;
			}
			else if(data > temp->data && temp->right!=NULL)
			temp=temp->right;
			else
			{
				temp->right=(bst*)malloc(sizeof(bst));
				temp=temp->right;
				temp->data=data;
				temp->left=NULL;
				temp->right=NULL;
				return root;
			}
		}
		
	}
}
void inorder(bst* node)
{
	
	if(node==NULL)
	return;
	else
	{
		inorder(node->left);
		printf("%d\n",node->data);
		inorder(node->right);
	}
}

int isEmpty()
{
	if(myQueue.front==-1)
	return 1;
	return 0;
}

void Enqueue(bst *node)
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
bst* Dequeue()
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

void push(bst *node)
{
	myStack.top++;
	myStack.arr[myStack.top] = node;
}

bst* pop()
{
	return myStack.arr[myStack.top--];
}

int isStackEmpty()
{
	if(myStack.top == -1)
		return 1;
	else
		return 0;
}

void printInLevelReverse(bst *root)
{
	bst *temp;
	Enqueue(root);
	while(!isEmpty())
	{
		printf("mohit\n");
		int size = myQueue.size;
		while(size > 0)
		printf("kumar\n");
		temp = Dequeue();
		push(temp);
		if(temp->right)
			Enqueue(temp->right);
		if(temp->left)
			Enqueue(temp->left);
		size--;
	}

	while(!isStackEmpty())
	{
		temp = pop();
		printf("%d  ",temp->data);
	}
}

