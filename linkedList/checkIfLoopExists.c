#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node node;

void printList(node *head);
void check(node *head);
node* insert(node *head,int data);


main()
{
	/*
	
	//creating a looped linked list;
	node *head = NULL,*temp,*someWhere;
	temp = (node*) malloc(sizeof(node));
	temp->data = 1;
	temp->next = (node*)malloc(sizeof(node));
	head = temp;
	temp = temp->next;
	
	temp->data = 2;
	temp->next = (node*)malloc(sizeof(node));
	temp = temp->next;

	temp->data = 3;
	temp->next = (node*)malloc(sizeof(node));
	temp = temp->next;

	temp->data = 4;
	temp->next = (node*)malloc(sizeof(node));
	temp = temp->next;	

	temp->data = 5;
	temp->next = (node*)malloc(sizeof(node));
	someWhere = temp;
	temp = temp->next;

	temp->data = 6;
	temp->next = (node*)malloc(sizeof(node));
	temp = temp->next;
	
	temp->data = 7;
	temp->next = (node*)malloc(sizeof(node));
	temp = temp->next;

	temp->data = 8;
	temp->next = (node*)malloc(sizeof(node));
	temp = temp->next;

	temp->data = 9;
	temp->next = someWhere;
	//printList(head);
	check(head);
	
	*/

	//checking the code against a terminating list.
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
	check(head);
}

void printList(node *head)
{
	node *temp = head;
	while(temp)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

void check(node *head)
{
	node *fast = head,*slow = head;
	while(fast && slow)
	{
		//printf("Inside while\n");
		fast = fast->next;
		if(fast == slow)
		{
			printf("Loop exists..\n");
			return;
		}
		else if(fast == NULL)
		{
			printf("Loop doesnt exits\n");
			return;
		}
		fast = fast->next;
		if(fast == slow)
		{
			printf("Loop exists..\n");
			return;
		}
		slow = slow->next;
	}
	printf("Loop doesnt exist\n");
	
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
