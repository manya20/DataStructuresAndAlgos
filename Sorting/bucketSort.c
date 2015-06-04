#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bucketSort(int arr1[],int arr2[],int max);

main()
{
	int arr1[100000],arr2[100000],i;
	srand(time(NULL));
	for(i=0;i < 100000; i++)
		arr1[i] = rand() % 100000;

	clock_t first=clock(),second;
	bucketSort(arr1,arr2,100000);
	second = clock();
	printf("%f\n",(float)(second - first)/ CLOCKS_PER_SEC);
	for(i=0;i<100;i++)
	printf("%d ",arr1[i]);
}

void bucketSort(int arr1[],int arr2[],int max)
{

	int i=0,j=0;
	while(i < max)
	{	
		
		arr2[i] = 0;
		i++;
	}
	
	i=0;
	while( i < max)
	{
		arr2[arr1[i++]]++;
	}
	i=0,j=0;
	while(j < max)
	{
		if(arr2[j] != 0)
		{
			int n = arr2[j];
			while(n > 0)
			{
				arr1[i++] = j;
				n--;
			}
		}
		j++;
	}
	
}
