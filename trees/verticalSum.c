#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST bst;

static int leftMost = 0 , rightMost = 0;

bst* insert(bst* root,int);
void setLeftMostAndRightMost(bst* node,int horizontalPos);
void verticalSum(bst *node,int arr[],int horizontalPos);

main()
{
	bst *root = NULL;
	int data;
	while(1)
	{
		printf("Enter the number to insert in bst and -1 to exit\n");
		scanf("%d",&data);
		if(data==-1)
		break;
		root = insert(root,data);
	}
	setLeftMostAndRightMost(root, 0);
	int size = leftMost * -1 + rightMost + 1;
	int *arr = (int*) malloc(sizeof(int) * size);
	int i;
	for(i = 0 ; i < size ; i++)
		arr[i] = 0;

	verticalSum(root,arr,0);
	for(i = 0 ; i < size ; i++)
		printf("%d ",arr[i]);

	printf("\n");
	
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
void setLeftMostAndRightMost(bst* node,int horizontalPos)
{
	if(node==NULL)
	return;
	else
	{
		if(horizontalPos < leftMost)
		{
			leftMost = horizontalPos;
		}
		else if(horizontalPos > rightMost)
		{
			rightMost = horizontalPos;
		}
		setLeftMostAndRightMost(node->left,horizontalPos - 1);
		setLeftMostAndRightMost(node->right,horizontalPos + 1);
	}
}

void verticalSum(bst *node,int arr[],int horizontalPos)
{
	if(node == NULL)
	{
		return;
	}
	else
	{
		int pos = horizontalPos +leftMost * -1;
		arr[pos] = arr[pos] + node->data;
		verticalSum(node->left,arr,horizontalPos - 1);
		verticalSum(node->right,arr,horizontalPos + 1);
	}
}
