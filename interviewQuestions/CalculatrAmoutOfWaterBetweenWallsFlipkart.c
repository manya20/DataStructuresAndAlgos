// The question is to calculate amout of water that can come between walls.. eg.. between walls of size {1,0,3}.. 1 unit of water can come.
//between walls {3,1,3}.. 2 units of water can come.

#include<stdio.h>
#include<stdlib.h>

void calculate(int arr[],int size);

main()
{
	int i,data,size = 0,arr[50];
	printf("Enter the Size of walls...enter -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		arr[size++] = data;
	}
	calculate(arr,size);
	
}


void calculate(int arr[],int size)
{
	int canHave = 0;
	int i = 0, j = 1;
	while(j < size)
	{
		//printf("here\n");
		if(arr[i] != 0 && arr[j] != 0)
		{
			///printf("in first if\n");
			if(arr[j] <= arr[i])
			{
				canHave = canHave + arr[j];
			}
			else
			{
				canHave = canHave + arr[i];
			}
			i = j;
			j++;
	
		}
		else
		{
			//printf("in second condition\n");
			if(arr[i] == 0 && arr[j] == 0)
			{
				i++;
				j++;
			}
			else if(arr[j] == 0)
			{
				j++;
			}
			else
			{
				i = j;
				j++;
			}
		}
	}
	printf("The walls can have at max %d units of water\n",canHave);
}

