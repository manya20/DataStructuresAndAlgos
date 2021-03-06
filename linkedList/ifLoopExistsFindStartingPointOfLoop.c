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
	//someWhere = temp;
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
	
	

	/*
	
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
	
	*/
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
	int flag = 0;	
	node *fast = head,*slow = head;
	while(fast && slow)
	{
		printf("Inside while\n");
		fast = fast->next;
		if(fast == slow)
		{
			printf("Loop exists..they met at data = %d\n",slow->data);
			flag = 1;
			break;
		}
		else if(fast == NULL)
		{
			printf("Loop doesnt exits\n");
			flag = 0;
			break;
		}
		fast = fast->next;
		if(fast == slow)
		{
			printf("Loop exists..they met at data = %d\n",slow->data);
			flag = 1 ;
			break;
		}
		slow = slow->next;
	}
	if(flag == 0)
	{
		printf("loop doesnt exits\n");
		return;
	}
	
	else
	{
		
		printf("Loop exists\n");
		node *temp = fast->next;
		int count1 = 1;
		while(temp != fast)
		{
			count1++;
			temp = temp->next;
		}
		slow = head;
		int count2 = 1;
		while(slow != fast)
		{
			count2++;
			slow = slow->next;
		}
		int i = 0;
		slow = head;
		if(count2 >= count1)
		{
			while(i < (count2 - count1 - 1))
			{
				slow = slow->next;
				i++;
			}
			printf("slow is at %d\nfast is at %d\n",slow->data,fast->data);
			/*
			while(slow != fast)
			{
				printf("inside second llopp\n");
				fast = fast->next;
				slow = slow->next;
			}
			*/
			printf("The starting point is at data = %d\n",slow->data);
			return;
		}
		else
		{
			while(i < (count1 - count2 - 1))
			{
				slow = slow->next;
				i++;
			}
			while(slow != fast)
			{
				printf("inside third llopp\n");
				fast = fast->next;
				slow = slow->next;
			}
			printf("The starting point is at data = %d\n",slow->data);
			return;
		}	
	}
	
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
