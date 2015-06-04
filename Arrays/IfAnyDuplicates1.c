#include<stdio.h>
#include<stdlib.h>


// The condition here is that no negatives are present

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
	int i,maxValueInArray = arr[0];
	for(i = 0; i < size;i++)
	{
		if(arr[i] > maxValueInArray)
			maxValueInArray = arr[i];
	}

	int b[maxValueInArray];
	for(i = 0;i < maxValueInArray;i++)
	{
		b[i] = 0;
	}
	for(i = 0; i < size;i++)
	{
		b[arr[i]]++;
		if(b[arr[i]] > 1)
		{
			printf("It has duplicates\n");
			return;
		}
	}
	printf("It does not have any duplicates\n");
}



















