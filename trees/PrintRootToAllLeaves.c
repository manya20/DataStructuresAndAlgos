#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST bst;

bst* insert(bst* root,int);
void inorder(bst*);
void printRootToAllLeaves(bst *node,int arr[],int length);
void printArray(int arr[],int length);
main()
{
	bst *root = NULL;
	int data,arr[20];
	while(1)
	{
		printf("Enter the number to insert in bst and -1 to exit\n");
		scanf("%d",&data);
		if(data==-1)
		break;
		root = insert(root,data);
	}
	printRootToAllLeaves(root,arr,0);
	
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

void printRootToAllLeaves(bst *node,int arr[],int length)
{

	if(node == NULL)
	{
		return;
	}
	else
	{
		arr[length++] = node->data;
		if(node->left == NULL && node->right == NULL)
		{
			printArray(arr,length);
		}
		else
		{
			printRootToAllLeaves(node->left,arr,length);
			printRootToAllLeaves(node->right,arr,length);
		}
	}
		
}


void printArray(int arr[],int length)
{
	int i;
	for(i = 0;i < length;i++)
		printf("%d ",arr[i]);
	printf("\n\n");
}

