#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node node;

node *insert(node *head,int data);
void printList(node *head);
node* pairWiseSwap(node *head);


main()
{
	node *head = NULL;
	int i,size = 0,data;
	printf("Enter the numbers..enter -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		head = insert(head,data);
	}
	printf("Printing elements before pairwise swapping:\n");	
	printList(head);
	head = pairWiseSwap(head);
	printf("Printing elements after pairwise swapping:\n");
	printList(head);
}

node* insert(node *head,int data)
{
	if(head == NULL)
	{
		head = (node*) malloc(sizeof(node));
		head->data = data;
		head->next = NULL;
	}
	else
	{
		node *temp = head;
		while(temp->next)
			temp = temp->next;
		temp->next = (node*)malloc(sizeof(node));
		temp = temp->next;
		temp->data = data;
		temp->next = NULL;
	}
	return head;
}

void printList(node *head)
{
	while(head)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

node* pairWiseSwap(node *head)
{
	if(head == NULL)
	{
		printf("no list\n");
		return NULL;
	}
	else if(head->next == NULL)
	{
		return head;
	}
	else
	{
		node *prev = NULL,*curr = head,*next1,*next2;
		while(curr)
		{
			next1 = curr->next;
			if(next1)
			{
				next2 = next1->next;
				curr->next = next2;
				next1->next = curr;
				if(curr == head)
				{
					head = next1;
				}
				else
				{
					prev->next = next1;
				}
				prev = curr;
				curr = next2;
			}
			else
				break;
		}
	}
	return head;
}

























