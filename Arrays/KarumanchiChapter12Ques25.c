#include<stdio.h>
#include<stdlib.h>

int findMedian(int arr[],int left,int right);
void quicksort(int arr[],int left,int right);
void swap(int arr[],int i,int j);
void findIfHaveSum(int arr[],int size,int num);
main()
{
	int i,data,size = 0,arr[50],num;
	printf("Enter the Numbers .. press -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		arr[size++] = data;
	}
	printf("Enter hte number whose summation is to be checked\n");
	scanf("%d",&num);
	findIfHaveSum(arr,size,num);

}

int findMedian(int arr[],int left,int right)
{
	int center = (left + right) / 2;
	if(arr[left] > arr[center])
		swap(arr,left,center);
	if(arr[center] > arr[right])
		swap(arr,center,right);
	if(arr[left] > arr[center])
		swap(arr,left,center);

	return arr[center];
}

void swap(int arr[],int i,int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;	
}

void quicksort(int arr[],int left,int right)
{
	if(left > right)
		return;
	if(left == right)
	{
		return;
	}
	/*if (right == left + 1)
	{
		if(arr[left] <= arr[right])
			return;
		else
			swap(arr,left,right);
	}*/
	int center = (left + right) / 2;
	int pivot = findMedian(arr,left,right);
	swap(arr,center,right);
	int i = left,j = right - 1;
	printf("New function called\n");
	while(1)
	{
		
		while(arr[i] <= pivot && i < right)
			i++;
		while(arr[j] >= pivot && j > left)
			j--;
		printf("inside loop.. i = %d  j = %d\n",i,j);
		if(i >= j)
			break;
		else
			swap(arr,i,j);
		
	}
	swap(arr,i,right);
	quicksort(arr,left,i-1);
	quicksort(arr,i+1,right);
}
void findIfHaveSum(int arr[],int size,int num)
{
	quicksort(arr,0,size - 1);
	int i = 0,j = size - 1;
	while(i <= j)
	{
		while(arr[j] > num - arr[i])
			j--;
		if(arr[j] == num - arr[i])
		{
			printf("It has the summation\n");
			return;
		}
		else
			i++;
	}
	printf("it has no summation\n");
}






























