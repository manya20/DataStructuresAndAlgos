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
int findKthLargest(bst *node,int k);
int count = 0;
main()
{
	bst *root = NULL;
	int data,k;
	while(1)
	{
		printf("Enter the number to insert in bst and -1 to exit\n");
		scanf("%d",&data);
		if(data==-1)
		break;
		root = insert(root,data);
	}
	//inorder(root);
	printf("Enter k\n");
	scanf("%d",&k);
	k = findKthLargest(root,k);
	printf("kth largest is %d\n",k);
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

int findKthLargest(bst *node,int k)
{
	int i;
	if(node == NULL)
		return 0;
	else
	{
		
		i = findKthLargest(node->right,k);
		count++;
		if(count == k)
			return node->data;
		else if(count > k)
			return i;
		else
			findKthLargest(node->left,k);

	}
}
