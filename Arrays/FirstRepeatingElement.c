#include<stdio.h>
#include<stdlib.h>


void findFirstRepeating(int arr[],int size);

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
	findFirstRepeating(arr,size);
}

void findFirstRepeating(int arr[],int size)
{
	int i,max = arr[0];
	for(i = 0;i < size;i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	int b[max];
	for(i = 0 ; i < max;i++)
	{
		b[i] = 0;
	}
	for(i = 0; i < size;i++)
	{
		b[arr[i]]++;
	}
	for(i = 0;i < size;i++)
	{
		if(b[arr[i]] > 1)
		{
			printf("%d is the first repeating element\n",arr[i]);
			return;
		}
	}
}




















