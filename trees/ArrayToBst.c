#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST bst;
int arr[]={3,4,7,9,10,12,14,20,24};
bst *root=NULL;
bst* makeBST(int,int);
void preOrder(bst *root);
main()
{
	makeBST(0,8);
	preOrder(root);
	
}
bst* makeBST(int left,int right)
{
	bst *node=(bst*)malloc(sizeof(bst));
	if(root==NULL)
	root=node;
	int mid=left + (right-left)/2;
	if(left==right)
	{
		node->data=arr[left];
			printf("%d ",arr[mid]);
		node->left=NULL;
		node->right=NULL;
		return node;
	}
	else if(left>right)
	return NULL;
	else
	{
		node->data=arr[mid];
		printf("%d ",arr[mid]);
		node->left=makeBST(left,mid-1);
		node->right=makeBST(mid+1,right);
	}
}
void preOrder(bst *root)
{
	bst *temp=root;
	if(temp==NULL)
	return;
	else
	{
		printf("\n%d ",temp->data);
		preOrder(temp->left);
		preOrder(temp->right);
	}
}
