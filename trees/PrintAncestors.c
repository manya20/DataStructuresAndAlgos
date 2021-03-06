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
int printAncestors(bst *node,int n);
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
	//inorder(root);
	printf("Enter the number to search for\n");
	scanf("%d",&data);
	printAncestors(root,data);
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

int printAncestors(bst *node,int n)
{
	
	if(node == NULL)
		return 0;
	else
	{
		
		if(node->data == n)
		{
			printf("%d  \n",node->data);
			return 1;
		}
		else
		{
			int i = printAncestors(node->left,n);
			if(i == 1)
			{
				printf("%d  \n",node->data);
				return 1;
			}
			else
			{
				i = printAncestors(node->right,n);
				if(i == 1)
				{
					printf("%d  \n",node->data);
					return 1;
				}
			}
		}	

	}


}
