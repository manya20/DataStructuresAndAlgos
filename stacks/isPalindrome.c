#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack
{
	int size;
	char *arr;
	int top;
};

typedef struct Stack stack;
void init(stack *st,int size);
int isFull(stack *st);
int isEmpty(stack *st);
void push(stack *st,char data);
char pop(stack *st);
void isPalindrome(stack *st,char arr[],int size);

main()
{
	stack *st = (stack*) malloc(sizeof(stack));
	int i,size = 0;
	char data;
	printf("Enter the size of input string\n");
	scanf("%d",&size);
	init(st,size);
	char arr[size];
	printf("Enter the input string. with characters..'a'(small).. 'b'(small)\n and 'X'(capital) where X represents middle of string\neg.. abbaXbbab..\nplease enter only a, b and X\n");
	i = 0;
	while(i < size)
	{
		
		scanf(" %c",&data);
		arr[i++] = data;
		
	}
	isPalindrome(st,arr,size);
}


void init(stack *st,int size)
{
	st->top = -1;
	st->size = size;
	st->arr = (char*)malloc(sizeof(char) * (st->size));
}

int isFull(stack *st)
{
	if(st->top == st->size - 1)
		return 1;
	else return 0;
}

int isEmpty(stack *st)
{
	if(st->top == -1)
		return 1;
	else
		return 0;
}

void push(stack *st,char data)
{
	if(!isFull(st))
	{
		st->arr[++st->top] = data;
	}
	else
	{
		printf("Stack is full\n");
	}
	return;
}



char pop(stack *st)
{
	if(!isEmpty(st))
	{
		return st->arr[st->top--];
	}
	return '\0';
}

void isPalindrome(stack *st,char arr[],int size)
{
	int i = 0 ;
	while(arr[i] != 'X')
	{
		push(st,arr[i++]);
	}
	i++;
	while(i < size)
	{
		char temp = pop(st);
		if(arr[i++] != temp)
		{
			printf("Not a palindrome\n");
			return;
		}
	}
	printf("It is a palindrome\n");
}

