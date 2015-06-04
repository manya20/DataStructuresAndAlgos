#include<stdio.h>
#include<stdlib.h>

void findMissingNumbers(int arr[],int size);
int findMedian(int arr[],int left,int right);
void quicksort(int arr[],int left,int right);
void swap(int arr[],int i,int j);

// input is distinct numbers between 0 - 99


main()
{
	int i,data,size = 0,arr[50];
	printf("Enter the  distinct Numbers between 0-99.. enter -1 to exit \n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		arr[size++] = data;
	}
	findMissingNumbers(arr,size);
}

void findMissingNumbers(int arr[],int size)
{

	quicksort(arr,0,size - 1);
	int i,counter = 0;
	for(i = 0;i <= size;i++)
	{
		if(i == size)
		{
			if(arr[size - 1] != 99)
				printf("%d-%d\n",arr[size - 1] + 1,99);
			return;
		}
		else if(i == 0 )
		{
			if(arr[i] != 0)
				printf("%d-%d\n",0,(arr[i] - 1)); 
			
		}
		else if(arr[i] == arr[i- 1] + 1 )
		{
			continue;
		}
		else
		{
			//printf("sfsdfd\n");
			printf("%d-%d\n",arr[i - 1] + 1,arr[i] - 1);

		}
		

	}
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
	//printf("New function called\n");
	while(1)
	{
		
		while(arr[i] <= pivot && i < right)
			i++;
		while(arr[j] >= pivot && j > left)
			j--;
		//printf("inside loop.. i = %d  j = %d\n",i,j);
		if(i >= j)
			break;
		else
			swap(arr,i,j);
		
	}
	swap(arr,i,right);
	quicksort(arr,left,i-1);
	quicksort(arr,i+1,right);
}























