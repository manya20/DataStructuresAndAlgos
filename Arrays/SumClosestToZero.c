#include<stdio.h>
#include<stdlib.h>

int findMedian(int arr[],int left,int right);
void quicksort(int arr[],int left,int right);
void swap(int arr[],int i,int j);
void closestSumToZero(int arr[],int size);




// here the array contains both positive and negative numbers.





main()
{
	int i,data,size = 0,arr[50];
	printf("Enter the Numbers .. press 0 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == 0)
			break;
		else
		arr[size++] = data;
	}
	closestSumToZero(arr,size);
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


void closestSumToZero(int arr[],int size)
{
	quicksort(arr,0,size - 1);
	int closestPositiveSumToZero = arr[size - 1],closestNegativeSumToZero = arr[0];
	int i = 0,j = size - 1;
	while(i < j)
	{
		int temp = arr[i] + arr[j];
		if(temp > 0)
		{
			if(temp < closestPositiveSumToZero)
			{
				closestPositiveSumToZero = temp;
			}
			j--;
		}
		else if(temp < 0)
		{
			if(temp < closestNegativeSumToZero)
			{
				closestNegativeSumToZero = temp;
			}
			i++;
		}
		else
		{
			printf("Smallest sum to zero is 0\n");
			return;
		}
	}
	if(closestPositiveSumToZero > -1 * closestNegativeSumToZero )
	{
		printf("Closest is less than zero and is %d\n",closestNegativeSumToZero);
		return;
	}
	else
	{
		printf("Closest is greater than zero and is %d\n",closestPositiveSumToZero);
	}

}






























