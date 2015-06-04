#include<stdio.h>
#include<stdlib.h>


void swap(int arr[],int i,int j);
void separateEvenAndOdd(int arr[],int left,int right);
void segregate(int arr[],int left,int right);


main()
{
	int i,data,size = 0,arr[50],k;
	printf("Enter the odd and even numbers Numbers .. press -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		arr[size++] = data;
	}
	separateEvenAndOdd(arr,0,size - 1);
	for(i = 0; i < size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	

}

void swap(int arr[],int i,int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;	
}

void separateEvenAndOdd(int arr[],int left,int right)
{
	if(left >= right)
		return;
	else
	{
		int mid = (left + right) / 2;
		separateEvenAndOdd(arr,left,mid);
		separateEvenAndOdd(arr,mid + 1,right);
		segregate(arr,left,right);
	}
	
}

void segregate(int arr[],int left,int right)
{

	int i = left,j = right;
	while(1)
	{
		while(arr[i] % 2 == 0)
			i++;
		while(arr[j] % 2 == 1)
			j--;
		if(i >= j)
			break;
		else
			swap(arr,i,j);
	}	

}
















































