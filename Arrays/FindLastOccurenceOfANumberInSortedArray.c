#include<stdio.h>
#include<stdlib.h>



int findFirstOccurence(int arr[],int left,int right,int data);
int findLastOccurence(int arr[],int left,int right,int data);
void findTotalOccurences(int arr[],int left,int right,int data);

main()
{
	int i,data,size = 0,arr[50];
	printf("Enter the numbrs such that they they sorted.. numbers may be repeated or not\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == 0)
			break;
		else
		arr[size++] = data;
	}
	printf("Enter the data to search for\n");
	scanf("%d",&data);
	findTotalOccurences(arr,0,size - 1,data);
	
}
void findTotalOccurences(int arr[],int left,int right,int data)
{
	int first =  findFirstOccurence(arr,left,right,data);
	int last =  findLastOccurence(arr,left,right,data);
	printf("no. of occurences = %d\n",(last - first + 1));
}








int findLastOccurence(int arr[],int left,int right,int data)
{
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(arr[mid] > data)
			right = mid - 1;
		else if(arr[mid] < data)
			left = mid + 1;
		else if(arr[mid] == data && arr[mid + 1] == data )
			left = mid + 1;
		else
		{
			printf("last occurence is at index %d\n",mid);
			return mid;
		}
	}
	if(arr[left] == data)
	{
		printf("last occurence is at index %d\n",left);
		return left;
	}
}

int findFirstOccurence(int arr[],int left,int right,int data)
{
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(arr[mid] > data)
			right = mid - 1;
		else if(arr[mid] < data)
			left = mid + 1;
		else if(arr[mid] == data && arr[mid - 1] == data )
			right = mid - 1;
		else
		{
			printf("first occurence is at index %d\n",mid);
			return mid;
		}
	}
	if(arr[left] == data)
	{
		printf("first occurence is at index %d\n",left);
		return left;
	}
}

























