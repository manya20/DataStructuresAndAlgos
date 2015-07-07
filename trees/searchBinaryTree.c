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
int search(bst *node,int data);

main()
{
	bst *root = NULL;
	int data;
	printf("Enter the numbers.. Although the insertion will be in binary search tree.\n the code will consider the tree as binary tree only\nEnter -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
		break;
		root = insert(root,data);
	}
	//inorder(root);
	printf("enter the number to search for\n");
	scanf("%d",&data);
	if(search(root,data))
		printf("NUmber is in the tree\n");
	else
		printf("Number is not in the tree\n");
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


int search(bst *node,int data)
{
	if(node == NULL)
		return 0;
	else
	{
		if(node->data == data)
			return 1;
		else
		{
			int i = search(node->left,data);
			if(i == 1)
				return 1;
			else
			{
				i = search(node->right,data);
				return i;
			}
		}
	}
}

























