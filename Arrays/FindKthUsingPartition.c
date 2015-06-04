#include<stdio.h>
#include<stdlib.h>

int findMedian(int arr[],int left,int right);
void findKthSmallest(int arr[],int left,int right,int k);
void swap(int arr[],int i,int j);







//Program is for distinct numbers.. 




main()
{
	int i,data,size = 0,arr[50],k;
	printf("Enter the Numbers .. press -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		arr[size++] = data;
	}
	printf("Enter k:\n");
	scanf("%d",&k);
	findKthSmallest(arr,0,size - 1,k);

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

void findKthSmallest(int arr[],int left,int right,int k)
{
	if(left == right)
	{
		printf("Kth Smallest:%d\n",arr[left]);
		return;
	}
	int center = (left + right) / 2;
	int pivot = findMedian(arr,left,right);
	swap(arr,center,right);
	int i = left,j = right - 1;
	while(1)
	{
		while(arr[i] <= pivot)
			i++;
		while(arr[j] > pivot)
			j--;
		if(i >= j)
			break;
		else
			swap(arr,i,j);
	}
	swap(arr,i,right);
	if(i == k - 1)
	{
		printf("The Kth smallest: %d and i:%d\n",arr[i],i);
		return;
	}

	else if(i > k - 1)
		findKthSmallest(arr,left,i - 1,k);
	else 
		findKthSmallest(arr,i + 1,right,k);
}
























