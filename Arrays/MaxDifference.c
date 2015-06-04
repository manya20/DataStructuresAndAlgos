#include<stdio.h>
#include<stdlib.h>



//while taking difference.. the number from which we are subtracting. should appear later.. eg..
//in a array with elements.. 2 3 10 6 4 8 1.. answer is 10 - 2  = 8
// array with elements.. 7 9 5 6 3 2 .. answer is 9 - 7  = 2;

int maxDiff = 0,arraySize;
void findMaxDiff(int arr[],int left,int right);
void merge(int arr[],int left,int right);



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
	arraySize = size;
	findMaxDiff(arr,0,size - 1);
	printf("Max diff is %d\n",maxDiff);

}


void findMaxDiff(int arr[],int left,int right)
{
	if(left == right)
	{
		return;
	}
	else
	{
		int diff;
		int mid = (left + right) / 2;
		findMaxDiff(arr,left,mid);
		findMaxDiff(arr,mid + 1,right);
		if( (diff = arr[right] - arr[left])  > 0)
		{
			if(diff > maxDiff)
			{
				maxDiff = diff;
				printf("current max diff is %d\n",maxDiff);
			}
		}
		merge(arr,left,right);
	}
}

void merge(int arr[],int left,int right)
{
	
	printf("left = %d... right = %d\n",left,right);
	int mid = (left + right) / 2;
	int buff[arraySize];
	int i = left,j = mid + 1,k = left;
	while(i <= mid && j <= right)
	{
		if(arr[i] <= arr[j])
		{
			buff[k++] = arr[i++];
		}
		else
		{
			buff[k++] = arr[j++];
		}
	}
	while(i <= mid)
		buff[k++] = arr[i++];
	while(j <= right)
		buff[k++] = arr[j++];

	for(k = left; k <= right;k++)
		arr[k] = buff[k];
	printf("merged array with left = %d and right = %d  is\n",left,right);
	for(k = left; k <= right;k++)
		printf("%d ",arr[k]);
	printf("\n");
}




















































