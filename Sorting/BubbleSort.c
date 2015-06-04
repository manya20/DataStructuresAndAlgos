#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int*,int*);
void BubbleSort(int arr[],int left,int right);

main()
{
	int arr[100000];
	srand(time(NULL));
	int i;
	for(i=0;i < 100000 ; i++)
	arr[i]= rand();
	clock_t first=clock(),second;
	printf("Starting...\n");
	BubbleSort(arr,0,i - 1);
	second = clock();
	printf("\n%f",(float)(second - first) / CLOCKS_PER_SEC );
	for(i=0;i<100;i++)
	printf("%d\n",arr[i]);
}

void BubbleSort(int arr[],int left,int right)
{
	int i,j,n = right - left + 1 ;
	for(i=0;i < n - 1;i++)
	{
		for(j = n - 1;j >  i ; j--)
		{
			if(arr[j] < arr[j - 1] )
			swap(arr + j ,arr + j - 1);
		}
	}
}
void swap(int *first,int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}
