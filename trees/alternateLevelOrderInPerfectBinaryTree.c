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
t* insert(t *root,int data);
void alternateLevelOrderInPerfectBinaryTree(t *root);
void inorder(t *node);

main()
{
	myQueue.front = myQueue.rear = -1;
	myQueue.size = 0;
	t *root = NULL;
	int i,data;
	printf("Enter the perfect binary  tree or else the program will not work.. enter -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		root = insert(root,data);
	}
	//inorder(root);
	alternateLevelOrderInPerfectBinaryTree(root);
	printf("\n");

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


t* insert(t *root,int data)
{
	t *temp=root;
	if(root==NULL)
	{	
		root=(t*)malloc(sizeof(t));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return;
	}
	else{
		while(1)
		{
			if(data < temp->data && temp->left!=NULL)
			temp=temp->left;
			else if(data < temp->data && temp->left==NULL)
			{
				temp->left=(t*)malloc(sizeof(t));
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
				temp->right=(t*)malloc(sizeof(t));
				temp=temp->right;
				temp->data=data;
				temp->left=NULL;
				temp->right=NULL;
				return root;
			}
		}
		
	}
}

void alternateLevelOrderInPerfectBinaryTree(t *root)
{
	int i;
	Enqueue(root);
	t *temp1,*temp2;
	while(!isEmpty())
	{
		temp1 = Dequeue();
		if(temp1 == root)
		{
			printf("%d\n",temp1->data);
			Enqueue(temp1->left);
			Enqueue(temp1->right);
			
		}
		else
		{
			temp2 = Dequeue();
			printf("%d %d\n",temp1->data,temp2->data);
			if(temp1->left)
				Enqueue(temp1->left);
			if(temp2->right)
				Enqueue(temp2->right);
			if(temp1->right)
				Enqueue(temp1->right);	
			if(temp2->left)
				Enqueue(temp2->left);
		}
	
	}
}

void inorder(t* node)
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

