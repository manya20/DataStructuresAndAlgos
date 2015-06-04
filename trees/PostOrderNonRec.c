#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST bst;

struct Stack
{
	int top;
	bst *arr[50];
};
typedef struct Stack st;
int isEmpty(st*);
void push(st*,bst*);
bst* pop(st*);
bst* insert(bst* root,int);
void inorder(bst*);
void postOrder(bst *root,st *s);
bst* top(st *s);
main()
{
	bst *root = NULL;
	int data;
	st *s = (st*) malloc(sizeof(st));
	s->top = -1;
	while(1)
	{
		printf("Enter the number to insert in bst and -1 to exit\n");
		scanf("%d",&data);
		if(data==-1)
		break;
		root = insert(root,data);
	}
	//inorder(root);
	postOrder(root,s);
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

int isEmpty(st *s)
{
	if(s->top == -1)
	{
		return 1;
	}
	else
		return 0;
}

void push(st *s,bst *node)
{
	s->arr[++s->top] = node;
}

bst* pop(st *s)
{
	return s->arr[s->top--];
}

bst* top(st *s)
{
	return s->arr[s->top];
}
void postOrder(bst *root,st *s)
{
	bst *temp = root;
	while(1)
	{
		if(temp != NULL)
		{
			push(s,temp);
			temp = temp->left;
		}		
		else
		{
			if(isEmpty(s))
				return;
			if(top(s)->right==NULL)
			{
				temp = pop(s);
				printf("%d\n",temp->data);
			}
			if(temp == top(s)->right)
			{
				printf("%d\n",top(s)->data);
				temp = pop(s);
			}
			if(!isEmpty(s))
				temp = top(s)->right;
			else
				temp = NULL;
		}








	}
}
