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
bst* delete(bst*,int n);
bst* findMax(bst*);
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
	inorder(root);
	printf("Enter the number to delete..\n");
	scanf("%d",&data);
	delete(root,data);
	inorder(root);
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

bst* findMax(bst *node)
{
	if(node->right == NULL)
		return node;
	else
	{
		bst *temp = findMax(node->right);
		return temp;
	}

}

bst* delete(bst *node,int n)
{
	if(node == NULL)
		return NULL;
	if(n > node->data)
		node->right = delete(node->right,n);
	else if(n < node->data)
		node->left = delete(node->left,n);
	else
	{
		if(node->left && node->right)
		{
			bst *temp = findMax(node->left);
			node->data = temp->data;
			delete(temp,n);
		}
		else if(node->left || node->right)
		{
			if(node->left)
				return node->left;
			else
				return node->right;
		}
		else
			return NULL;
		

	}
	return node;
}
