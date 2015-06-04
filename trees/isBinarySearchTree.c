#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST bst;
bst *root;
void insert(int);
void inOrder(bst*);
int isBinarySearchTree(bst*);
main()
{
	root=NULL;
	int data,check;
		bst *root2,*temp1,*temp2,*temp3,*temp4;
			root2=(bst*)malloc(sizeof(bst));
	temp1=root2;
	temp1->data=1;
	temp1->left=(bst*)malloc(sizeof(bst));
	temp2=temp1->left;
	temp2->data=2;
	temp1->right=(bst*)malloc(sizeof(bst));
	temp3=temp1->right;
	temp3->data=3;
	temp2->right=NULL;
	temp2->left=(bst*)malloc(sizeof(bst));
	temp2=temp2->left;
	temp2->data=4;
	temp2->left=NULL;
	temp2->right=NULL;
	temp3->left=(bst*)malloc(sizeof(bst));
	temp2=temp3->left;
	temp2->data=5;
	temp2->left=NULL;
	temp2->right=NULL;
	temp3->right=(bst*)malloc(sizeof(bst));
	temp3=temp3->right;
	temp3->data=6;
	temp3->left=NULL;
	temp3->right=(bst*)malloc(sizeof(bst));
	temp2=temp3->right;
	temp2->left=(bst*)malloc(sizeof(bst));
	temp2->right=NULL;
	temp2->data=7;
	temp2=temp2->left;
	temp2->left=NULL;
	temp2->right=NULL;
	temp2->data=11;
		while(1)
	{
		printf("Enter the number to insert in bst and -1 to exit\n");
		scanf("%d",&data);
		if(data==-1)
		break;
		insert(data);
	}
	inOrder(root);
	check=isBinarySearchTree(root);
	if(check==1)
	printf("\nit is a BST");
	else 
	printf("\n it is not a BST");
	check=isBinarySearchTree(root2);
	if(check==1)
	printf("\nit is a BST");
	else 
	printf("\n it is not a BST");
}

void insert(int data)
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
				
				return;
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
				return;
			}
		}
		
	}
}
void inOrder(bst* node)
{
	if(node==NULL)
	return;
	else
	{
		inOrder(node->left);
		printf("%d\n",node->data);
		inOrder(node->right);
	}
}
int isBinarySearchTree(bst *node)
{
	bst *temp=node;
	int i;
	if(node==NULL)
	return 1;
	else if(temp->left==NULL && temp->right==NULL)
	return 1;
	else if(temp->left && temp->right)
	{
		if(temp->left->data < temp->data && temp->right->data > temp->data)
		{
			i=isBinarySearchTree(temp->left);
			if(i==1)
			{
			i=isBinarySearchTree(temp->right);
			return i;
			}
			else return 0;
		
		}
		else
		return 0;
	}
	
	else if(temp->right==NULL && temp->left)
	{
		if(temp->left->data < temp->data)
		{
			i=isBinarySearchTree(temp->left);
			return i;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(temp->right->data > temp->data)
		{
			i=isBinarySearchTree(temp->right);
			return i;
		}
		else
		return 0;
	}
}
