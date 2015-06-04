#include<stdio.h>
#include<stdlib.h>



void findK(int arr[],int left,int right);




main()
{
	int i,data,size = 0,arr[50];
	printf("Enter the Numbers such that till some index k the numbers are increasing and after it .. the nummbers are decreasing\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == 0)
			break;
		else
		arr[size++] = data;
	}
	findK(arr,0,size - 1);
	
}

void findK(int arr[],int left,int right)
{
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(right == left + 1)
		{
			if(arr[left] < arr[right])
			{
				printf("K is %d\n",right);
			}
			else
			{
				printf("K is %d\n",left);
				
			}
			break;
		}
		if(arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
		{
			left = mid + 1;
		}
		else if(arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])
		{
			right = mid - 1;
		}
		else
		{
			printf("the Index K is %d\n",mid);
			break;
		}
	}
}
