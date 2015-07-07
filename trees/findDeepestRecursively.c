#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST bst;

static int deepestLevel = -1;
static bst *deepestNode = NULL;

bst* insert(bst* root,int);
void find(bst *node,int depth);
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
	find(root,0);
	printf("deepest node is at level %d and its data is %d\n",deepestLevel,deepestNode->data);
	
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

void find(bst *node,int depth)
{
	if(node == NULL)
		return;
	else
	{
		if(depth > deepestLevel)
		{
			deepestNode = node;
			deepestLevel = depth;
		}
		find(node->left,depth + 1);
		find(node->right,depth + 1);
	
	}
}






























