#include<stdio.h>
#include<stdlib.h>



void findK(int arr[],int left,int right,int data);
void binarySearch(int arr[],int left,int right,int data);



main()
{
	int i,data,size = 0,arr[50];
	printf("Enter the numbrs such that they are already sorted and rotated\n");
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
	findK(arr,0,size - 1,data);
	
}

void findK(int arr[],int left,int right,int data)
{
	int size = right + 1;
	int i;
	for(i = 0; i < size - 1;i++)
	{
		if(arr[i + 1] < arr[i])
		{
			i++;
			break;
		}
	}
	if(i == size - 1)
	{
		printf("it is a fully rotated array..\n ");
		binarySearch(arr,left,right,data);
	}
	else
	{
		if(arr[i] == data)
		{
			printf("data is at index %d\n",i);
		}
		else if(data >= arr[i + 1] && data <= arr[right] )
		{
			binarySearch(arr,i + 1,right,data);
			return;
		}
		else
		{
			binarySearch(arr,left,i - 1,data);
			return;
		}
	}
}
void binarySearch(int arr[],int left,int right,int data)
{
	int mid;
	while(left < data)
	{
		mid = (left + right) / 2;
		if(arr[mid] == data)
		{
			printf("data is at index %d\n",mid);
			return;
		}
		else if(data > arr[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("data is not present in array\n");
}

























