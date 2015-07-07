#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node node;

node* insert(node *head,int data);
node* delete(node *head,int nodeNum);

main()
{
	node *head = NULL;
	int i,size = 0,data,n;
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
	node *temp = head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
	printf("Enter the nth node u wanna delete starting from 0th node\nCaution: n must be less than size of the LinkedList\n");
	scanf("%d",&n);
	head = delete(head,n);
	printf("After deletion\n");
	temp = head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
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

node* delete(node *head,int nodeNum)
{
	if(nodeNum == 0)
	{
		node *temp = head;
		head = head->next;
		free(temp);
	}
	else
	{
		node *prev = head,*curr = head->next,*temp;
		int i = 1;
		while(i != nodeNum)
		{
			prev = curr;
			curr = curr->next;
			i++;
		}
		temp = curr;
		prev->next = curr->next;
		free(temp);
	}
	return head;
}
