#include<stdio.h>
#include<stdlib.h>

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST bst;
int leftmostHorizontalDistance,rightmostHorizontalDistance,equalizer;
void setHorizontal(bst *node,int horizontalDistance);
bst* insert(bst* root,int);
void bottomUpView(bst *node,int *levelarr,int finalarr[],int level,int horizontalDistance);
main()
{
	bst *root = NULL;
	int data,i;
	while(1)
	{
		printf("Enter the number to insert in bst and -1 to exit\n");
		scanf("%d",&data);
		if(data==-1)
		break;
		root = insert(root,data);
	}
	setHorizontal(root,0);
	equalizer = -1 * leftmostHorizontalDistance;// since array index starts from 0. and leftmost can be negative..to get rid of that
						    //need this equalizer.. u can see what i mean in method bottomUpView();
	int *arr = (int*)malloc(sizeof(int)*(equalizer + rightmostHorizontalDistance + 1));
	int *finalarr = (int*)malloc(sizeof(int)*(equalizer + rightmostHorizontalDistance + 1));
	int size = equalizer + rightmostHorizontalDistance + 1;
	for(i = 0 ; i < size ; i++)
		arr[i] = -1;
	bottomUpView(root,arr,finalarr,0,0);
	for(i = 0;i < size ; i++)
		printf("%d ",finalarr[i]);

	printf("\n");	
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
void setHorizontal(bst *node,int horizontalDistance)
{
	if(node == NULL)
		return;
	else
	{
		setHorizontal(node->left,horizontalDistance - 1);
		if(horizontalDistance < leftmostHorizontalDistance)
			leftmostHorizontalDistance = horizontalDistance;
		else if(horizontalDistance > rightmostHorizontalDistance)
			rightmostHorizontalDistance = horizontalDistance;
		setHorizontal(node->left,horizontalDistance + 1);
	}
}

void bottomUpView(bst *node,int levelarr[],int finalarr[],int level,int horizontalDistance)
{
	if(node == NULL)
		return;
	else
	{
		bottomUpView(node->left,levelarr,finalarr,level + 1,horizontalDistance - 1);
		if(levelarr[horizontalDistance + equalizer] <= level )
		{
			levelarr[horizontalDistance + equalizer] = level;
			finalarr[horizontalDistance + equalizer] = node->data;
		}
		bottomUpView(node->right,levelarr,finalarr,level + 1,horizontalDistance + 1);
		
	}
	
}

























