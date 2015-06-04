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
int findLCA(bst*,int n1,int n2);
main()
{
	bst *root = NULL;
	int data,n1,n2;
	while(1)
	{
		printf("Enter the number to insert in bst and -1 to exit\n");
		scanf("%d",&data);
		if(data==-1)
		break;
		root = insert(root,data);
	}
	//inorder(root);
	printf("Enter the range..\n");
	scanf("%d %d",&n1,&n2);
	data = findLCA(root,n1,n2);
	if(data != 0)
		printf("%d is LCA\n",data);
	else
		printf("No LCA\n");
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

int findLCA(bst *node,int n1,int n2)
{

	if(node == NULL)
		return 0;
	else
	{
		int i = findLCA(node->left,n1,n2);
		if(i != 0)
			return i;
		else
		{
			if(node->data > n1 && node->data < n2)
				return node->data;
			else
				return findLCA(node->right,n1,n2);
		}
	}
		
}
