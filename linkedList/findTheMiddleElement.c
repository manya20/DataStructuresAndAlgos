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
void findMiddleElement(node *head);

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
	printf("Printing elements:\n");	
	printList(head);
	findMiddleElement(head);	
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

void findMiddleElement(node *head)
{
	if(head == NULL)
	{
		printf("No list\n");
		return;
	}
	else if(head->next == NULL || head->next->next == NULL)
	{
		printf("Middle element is %d\n",head->data);
		return;
	}
	else
	{
		node *fast = head,*slow = head;
		while(fast)
		{
			fast = fast->next;
			if(fast == NULL)
				break;
			fast = fast->next;
			slow = slow->next;
		}
		printf("Middle element is %d\n",slow->data);
	}
}
























































