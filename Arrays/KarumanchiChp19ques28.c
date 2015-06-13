#include<stdio.h>
#include<stdlib.h>

void rearrange(int arr[],int left,int right);
void swap(int arr[],int i,int j);


main()
{
	int i,data,size = 0,arr[50];
	printf("Enter the Numbers in the format .. a1 a2 a3...an b1 b2 b3.. bn.\n for eg.. 1 2 3 4 5 1 2 3 4 5\n..press -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		arr[size++] = data;
	}
	rearrange(arr,0,size - 1);
	for(i = 0 ; i < size ; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void rearrange(int arr[],int left,int right)
{
	if(right == left + 1 || right == left)
		return;
	int mid = (left + right) / 2; //
	int i = ((mid + left) / 2) + 1;
	int j = mid + 1;
	while(i <= mid)
	{
		swap(arr,i++,j++);
	}
	for(i = left ; i <= right ; i++)
		printf("%d ",arr[i]);
	printf("\n");
	rearrange(arr,left,mid);
	rearrange(arr,mid + 1,right);	
}


void swap(int arr[],int i,int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}























