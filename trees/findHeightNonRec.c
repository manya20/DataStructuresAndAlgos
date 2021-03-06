#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST bst;

struct Queue
{
	int size;
	int front,rear;
	bst *arr[50];
};

typedef struct Queue q;
void Enqueue(bst *node,q* queue);
bst* Dequeue(q*);
int isFull(q*);
int isEmpty(q*);
int size(q*);
bst* insert(bst* root,int);
void inorder(bst*);
void findHeightNonRec(bst *root,q*);
main()
{
	bst *root = NULL;
	int data;
	q myQueue;
	myQueue.size = 0;
	myQueue.front = myQueue.rear = -1;
	while(1)
	{
		printf("Enter the number to insert in bst and -1 to exit\n");
		scanf("%d",&data);
		if(data==-1)
		break;
		root = insert(root,data);
	}
	//inorder(root);
	printf("-------------\n");
	//printf("queue size = %d front = %d rear = %d", myQueue.size,myQueue.front,myQueue.rear);
	findHeightNonRec(root,&myQueue);
}

bst* insert(bst *root,int data)
{
	bst *temp=root;
	if(root==NULL)
	{	
		root=(bst*)malloc(sizeof(bst));
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

int size(q* queue)
{
	return queue->size;
}

int isEmpty(q* queue)
{
	if(queue->front == -1)
		return 1;
	else
		return 0;
}

int isFull(q *queue)
{
	if(queue->rear == 49)
		return 1;
	else
		return 0;
}

void Enqueue(bst* node,q* queue)
{
	if(queue->front == -1)
	{
		queue->size++;
		queue->front = queue->rear = 0;
		queue->arr[queue->rear] = node;
		return;
	}
	else
	{
		queue->size++;
		queue->arr[++queue->rear] = node;
	}

}

bst* Dequeue(q* queue)
{
	if(queue->front == queue->rear)
	{
		queue->size--;
		int temp = queue->rear;
		queue->rear = queue->front = -1;
		return queue->arr[temp];
	}
	else
	{
		queue->size--;
		return queue->arr[queue->front++];
	}
}

void findHeightNonRec(bst *root,q* queue)
{
	int height = 0;
	
	Enqueue(root,queue);
	//Enqueue(root->left,queue);
	//printf("size is %d\n",queue->size);
	while(!isEmpty(queue))
	{
		
		int  i = size(queue);
		while(i > 0)
		{
			
			bst *temp = Dequeue(queue);
			if(temp->left)
				Enqueue(temp->left,queue);
			if(temp->right)
				Enqueue(temp->right,queue);
			i--;
		}
		//printf("kumar..........\n\n\n");
		height++;
	}
	printf("height is %d  \n",height);
	return ;
}
