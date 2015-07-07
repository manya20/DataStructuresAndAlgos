#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node node;

node *insert(node *head,int data);
node *printList(node *head);

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
	
}

printList(node *head)
{
	while(head)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

node *insert(node *head,int data)
{
	if(head == NULL)
	{
		head = (node*) malloc(sizeof(node));
		head->data = data;
		head->next = NULL;
	}
	else if(data <= head->data)
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = head;
		head = temp;
	}
	else
	{
		node *curr = head->next,*prev = head,*temp;
		while(curr && curr->data <= data)
		{
			prev = curr;
			curr = curr->next;
		}
		if(curr == NULL)
		{
			temp = (node*)malloc(sizeof(node));
			temp->data = data;
			temp->next = NULL;
			prev->next = temp;
		}
		else
		{
			temp = (node*)malloc(sizeof(node));
			temp->data = data;
			temp->next = prev->next;
			prev->next = temp;
		}
	}
	return head;
}















































