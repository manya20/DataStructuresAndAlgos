#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mergeSort(int arr[],int left,int right);
void merge(int arr[],int left,int right);
int temp[100000];
main()
{
	int arr[100000],i=0;
	srand(time(NULL));
	while(i < 100000)
	{
		arr[i]=rand()  ;
		i++;
	}
	
	printf("Starting...\n");
	clock_t first = clock(),second;
	mergeSort(arr,0,100000 - 1);
	second = clock();
	printf("%f\n",(float)(second - first)/CLOCKS_PER_SEC);
	i=0;
	while(i<100)
	{
		printf("%d ",arr[i++]);
	}
}

void mergeSort(int arr[],int left,int right)
{
	int center = (left + right) / 2;
	if(left == right)
	return;
	else
	{
		mergeSort(arr,left,center);
		mergeSort(arr,center + 1,right);
		merge(arr,left,right);
	}
}

void merge(int arr[],int left,int right)
{
	int center = (left + right) / 2,i=left,j=center + 1;
	int tempPos=left, k = -1;
	
	while(i <= center && j <= right)
	{
		if(arr[i] < arr[j])
		{
			temp[tempPos++]=arr[i++];
		}
		else
		{
			temp[tempPos++] = arr[j++];
		}
	}
	while(i <= center)
	temp[tempPos++] = arr[i++];
	
	while(j <= right)
	temp[tempPos++] = arr[j++];
	int a=left;
	while(a <= right)
	{
		arr[a++]=temp[a];	
	}
}
