#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST bst;
int counter = 0,k;
bst* insert(bst* root,int);
void findKthSmallest(int arr[],int size);
int inorder(bst *node);






// THE SOLUTION IS FOR DISTINCT NUMBERS



main()
{
	int i,data,size = 0,arr[50];
	printf("Enter the Numbers .. press -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		arr[size++] = data;
	}
	printf("Enter the value of K\n");
	scanf("%d",&k);
	findKthSmallest(arr,size);
}

void findKthSmallest(int arr[],int size)
{
	bst *root = NULL;
	int i;
	for(i = 0 ; i < size ;i++)
	{
		root = insert(root,arr[i]);
	}
	int num = inorder(root);
	printf("Smallest num: %d\n",num);
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

int inorder(bst *node)
{
	int num;
	if(node == NULL)
	{
		return  0 ;
	}
	else
	{
		num = inorder(node->left);
		counter++;
		if(counter == k)
		{
			return node->data;
		}
		else if(counter < k)
			num = inorder(node->right);
		else
			return num;
	}
	return num;
}


































