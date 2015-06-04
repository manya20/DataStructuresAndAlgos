#include<stdio.h>
#include<stdlib.h>


// The condition here is that no negatives are present and the range of numbers is 0 to size - 1; 

void IfAnyDuplicate(int arr[],int size);

main()
{
	int i,size = 0,arr[50],data;
	printf("Enter the numbers.. Enter -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
			arr[size++] = data;
	}
	IfAnyDuplicate(arr,size);
}

void IfAnyDuplicate(int arr[],int size)
{
	int i,temp;
	for(i = 0 ;i < size;i++)
	{
		if(arr[i] < 0)
		{
			if(arr[-1 * arr[i]] < 0)
			{
				printf("it contains duplicates\n");
				return;
			}
			else
			{
				arr[-1 * arr[i]] = -1 * arr[-1 * arr[i]];
			}
		}
		else
		{
			if(arr[arr[i]] < 0)
			{
				printf("it contains duplicates\n");
				return;
			}
			else
			{
				arr[arr[i]] = -1 * arr[arr[i]];
			}
		}
	}
	printf("No duplicates\n");
}






















