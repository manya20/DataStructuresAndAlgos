#include<stdio.h>
#include<stdlib.h>

void findMinAndMax(int arr[],int size);

main()
{
	int i,data,size = 0,arr[50];
	printf("Enter the Numbers .. press -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		arr[size++] = data;
	}

	findMinAndMax(arr,size);
}

void findMinAndMax(int arr[],int size)
{
	int min = arr[0],max = arr[0],i;
	for(i = 1 ; i + 1 < size ; i = i + 2)
	{
		if(arr[i] <= arr[i + 1] )
		{
			if(arr[i] < min)
				min = arr[i];
			if(arr[i + 1] > max)
				max = arr[i + 1];
		}
		else
		{
			if(arr[i + 1] < min)
				min = arr[i + 1];
			if(arr[i] > max)
				max = arr[i];
		}
	}
	if(i == size)
	{
		printf("Minimum:%d\nMaximum:%d\n",min,max);
		return;
	}
	else
	{
		if(arr[i] < min)
			min = arr[i];
		else if(arr[i] > max)
			max = arr[i];
		printf("Minimum:%d\nMaximum:%d\n",min,max);
		return;
	}
}






















