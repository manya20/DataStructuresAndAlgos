#include<stdio.h>
#include<stdlib.h>

struct AVL
{
	int data;
	struct AVL *left;
	struct AVL *right;
	int height;
};

typedef struct AVL avl;
avl *root;
avl* insert(int data,avl *node);
int height(avl*);
int max(int,int);
avl* singleRotationLL(avl*);
avl* singleRotationRR(avl*);
avl* doubleRotationLR(avl*);
avl* doubleRotationRL(avl*);
void inOrder(avl*);
main()
{
	root=NULL;
	int data;
	while(1)
	{
		printf("Enter the element.Enter -1 to exit");
		scanf("%d",&data);
		if(data==-1)
		break;
		else
		root=insert(data,root);
		inOrder(root);
	}
}
avl* insert(int data,avl *node)
{
	avl *temp=node;
	if(node==NULL)
	{
		node=(avl*)malloc(sizeof(avl));
		node->data=data;
		node->height=0;
		node->left=NULL;
		node->right=NULL;
		temp=node;
		return temp;
	}
	else if(data < node->data)
	{
		temp->left=insert(data,temp->left);
		if(height(temp->left) - height(temp->right)== 2)
		{
			if(data < temp->left->data)
			 temp=singleRotationLL(temp);
			 else
			 temp=doubleRotationLR(temp);
		}
	}
	else if(data > node->data)
	{	
		temp->right=insert(data,temp->right);
		if(height(node->right) - height(node->left) == 2)
		{
			if(data > temp->right->data)
			temp=singleRotationRR(temp);
			else
			temp=doubleRotationRL(temp);
		}
	}
	temp->height=max(height(temp->left),height(temp->right)) + 1;
	return temp;
}
int max(int left,int right)
{
	if(left > right)
	return left;
	if(right > left)
	return right;
	else
	return left;
}
int height(avl *node)
{
	if(node==NULL)
	return -1;
	else
	return node->height;
}
avl* singleRotationLL(avl *node)
{
	avl *temp1=node->left->right,*temp2=node->left;
	temp2->right=node;
	node->left=temp1;
	
	node->height=max(height(node->left),height(node->right))+1;
	temp2->height=max(height(temp2->left),node->height)+1;
	return temp2;
	
}
avl* singleRotationRR(avl *node)
{
	avl *temp1=node->right->left,*temp2=node->right;
	temp2->left=node;
	node->right=temp1;
	
	node->height=max(height(node->left),height(node->right))+1;
	temp2->height=max(height(temp2->left),node->height)+1;
	
	return temp2;
}
avl* doubleRotationLR(avl *node)
{
	singleRotationRR(node->left);
	singleRotationLL(node);
}
avl* doubleRotationRL(avl *node)
{
	singleRotationLL(node->right);
	singleRotationRR(node);
}
void inOrder(avl *node)
{
	avl *temp=node;
	if(temp==NULL)
	return;
	else
	{
		inOrder(temp->left);
		printf("%d\n",temp->data);
		inOrder(temp->right);
	}
}
