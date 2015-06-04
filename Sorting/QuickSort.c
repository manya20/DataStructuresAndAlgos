#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quickSort(int arr[],int left,int right);
int median(int arr[],int left,int right);
void swap(int*,int*);

main()
{
	int arr[1000],i;
	printf("Starting...\n");
	i=0;
	srand(time(NULL));
	while(i < 1000)
	{
		arr[i]=rand();
		i++;
	}
	clock_t first=clock(),second;
	quickSort(arr,0,1000 - 1);
	second=clock();
	printf("%f\n",(float)(second - first)/CLOCKS_PER_SEC);
	for(i=0;i<100;i++)
	printf("%d ",arr[i]);
}

void quickSort(int arr[],int left,int right)
{
	if(left == right)
	return;
	if(right == left + 1)
	{
		if(arr[left] > arr[right])
		swap(arr + left,arr + right);
		return;
	}
	else
	{
		int center = (left + right) / 2,pivot,i,j;
		pivot=median(arr,left,right);
		swap(arr + center,arr + right - 1);
		i=left;
		j=right - 2;
		while(1)
		{
			while(arr[i] < pivot)
			i++;
			while(arr[j] > pivot)
			j--;
			if(i < j)
			swap(arr + i,arr + j);
			else
			break;
		}
		swap(arr + i,arr + right - 1);
		quickSort(arr,left,center);
		quickSort(arr,center + 1,right);
	}
	
}

int median(int arr[],int left,int right)
{
	int center = (left + right) / 2;
	if(arr[left] > arr[center])
	swap(arr + left, arr + center);
	if(arr[left] > arr[right])
	swap(arr + left,arr + right);
	if(arr[center] > arr[right] )
	swap(arr + center,arr + right);
	
	return arr[center];
}

void swap(int *first,int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}
