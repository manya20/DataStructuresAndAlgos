#include<stdio.h>
#include<stdlib.h>



void findK(int arr[],int left,int right,int data);

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
	findK(arr,0,size - 1,data);
	
}


void findK(int arr[],int left,int right,int data)
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
			printf("first occurence is at index inside %d\n",mid);
			return;
		}
	}
	if(arr[left] == data)
	{
		printf("first occurence is at index outside %d\n",left);
		return;
	}
}

























