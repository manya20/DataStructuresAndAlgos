#include<stdio.h>

void check(int a[],int b[],int size1,int size2);

main()
{
	int i,data,a[20],b[20],size1 = 0,size2 = 0;
	printf("Enter the sorted elements in first array.. enter -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
			a[size1++] = data;
	}
	printf("Enter the sorted elements in Second array.. enter -1 to exit\n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
			b[size2++] = data;
	}
	check(a,b,size1,size2);
}

void check(int a[],int b[],int size1,int size2)
{
	int i = 0,j = 0;
	while(1)
	{
		while(b[j] < a[i] && j < size2)
			j++;
		if(j >= size2)
			break;
		else if(b[j] == a[i])
		{
			printf("yes they have common elements\n%d is common in both of them\n",b[j]);
			return;
		}
		else
		{
			while(a[i] < b[j] && i < size1)
				i++;
			if(i >= size1)
				break;
			else if(a[i] == b[j])
			{
				printf("yes they have common elements\n%d is common in both of them\n",b[j]);
				return;
			}
			else
				continue;
		}
	}
	printf("no common elements\n");
}































