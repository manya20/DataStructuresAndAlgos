#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST bst;

int sum;
bst* insert(bst* root,int);
void sumOfLeftLeaves(bst *node,int isItLeftChild);

main()
{
	bst *root = NULL;
	int data;
	printf("Enter the number to insert in bst and -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
		break;
		root = insert(root,data);
	}
	 sumOfLeftLeaves(root,0);
	printf("Sum of left leaves = %d\n",sum);
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

void sumOfLeftLeaves(bst *node,int isItLeftChild)
{
	if(node == NULL)
		return ;
	else
	{
		sumOfLeftLeaves(node->left,1);
		if(isItLeftChild == 1)
		{
			sum = sum + node->data;
			printf("It is left child..data's value = %d\n",node->data);
		}
		sumOfLeftLeaves(node->right,0);
	}
	return ;
}
























