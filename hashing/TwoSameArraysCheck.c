#include<stdio.h>
#include<stdlib.h>
struct element
{
	int num,count;
};
typedef struct element node;

struct HashTable
{
	int tableSize;
	node arr[101];
};

typedef struct HashTable htable;

htable* initialize(htable *ht);
void insert(htable *ht,int num);
int hashFunc(int num);
void check(htable *ht,int arr1[],int arr2[],int size1,int size2);
int search(htable *ht,int num);
main()
{
	htable *ht = NULL;
	ht = initialize(ht);
	int i,arr1[] = {8,2,6,1,12,3,7,13,6,2,2,2,2,1,8,7,3,7,3},arr2[] = {8,2,6,1,12,3,7,13,6,2,2,2,2,1,8,7,3,7,3} ;
	//printf("done\n%d\n",ht->arr[6].count);
	printf("done\n");
	int size1 = sizeof(arr1) / sizeof(int) , size2 = sizeof(arr2) / sizeof(int);
	check(ht,arr1,arr2,size1,size2);
}

htable* initialize(htable *ht)
{
	ht = (htable*) malloc(sizeof(htable));
	int i;
	ht->tableSize = 101;
	for(i = 0;i < 101;i++)
	{
		ht->arr[i].count = 0;
		ht->arr[i].num = -1;
	}
	return ht; 
}

int hashFunc(int num)
{
	return (num % 10);
}

void insert(htable *ht,int num)
{
	int index = hashFunc(num);
	if(ht->arr[index].num == -1)
	{
		ht->arr[index].num = num;
		ht->arr[index].count++;
		return;
	}
	else
	{
		int collision = 0;
		while(ht->arr[index].num != -1 && ht->arr[index].num !=num)
		{
			index = index + 2*collision++ + 1;
			index = index % ht->tableSize;
		}
		if(ht->arr[index].num == num)
		{
			ht->arr[index].count++;
			return;
		}
		else
		{
			ht->arr[index].count++;
			ht->arr[index].num = num;
			return;
		}
	}
}

void check(htable *ht,int arr1[],int arr2[],int size1,int size2)
{
	int i,index;
	
	if(size1 != size2)
	{
		printf("they are not same\n");
		return;
	}
	else
	{
		printf("in here\n");
		for(i = 0;i < size1;i++)
		{
			insert(ht,arr1[i]);
		}
		
		for(i = 0 ; i < size1 ; i ++)
		{
			index = search(ht,arr2[i]);
			if(index == -1)
				break;
			else
			{
				ht->arr[index].count--;
			}
		}
		
		if(i != size1)
		{
			printf("They are not same\n");
			return;
		}
		else
		{
			for(i = 0 ; i < ht->tableSize ; i++)
			{
				if(ht->arr[i].count != 0)
					break;
			}
			if(i != ht->tableSize)
			{
				printf("They are not same\n");
				return;
			}
			else
			{
				printf("They are same\n");
				return;
			}
		}
	}
}

int search(htable *ht,int num)
{
	int index = hashFunc(num);
	if(ht->arr[index].num == -1)
	{
		return -1;
	}
	else
	{	
		int collision = 0;
		while(ht->arr[index].num != -1 && ht->arr[index].num != num)
		{
			index = index + 2*collision++ + 1;
			index = index % ht->tableSize;
		}
		if(ht->arr[index].num == -1)
			return -1;
		else
			return index;
	}
}
