#include<stdio.h>
#include<stdlib.h>






// the inputs are assumed to be only positive.
// the hasing solution would be better if u have a good hash function.. or u can solve it in java using hash api
void groupTogetherRepeatedNumbers(int arr[],int size);


main()
{
	int i,data,size = 0,arr[50];
	printf("Enter the  postitive numbers \n");
	while(1)
	{
		scanf("%d",&data);
		if(data == -1)
			break;
		else
		arr[size++] = data;
	}
	groupTogetherRepeatedNumbers(arr,size);
	for(i = 0; i < size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void groupTogetherRepeatedNumbers(int arr[],int size)
{

	int i,max = arr[0],c[size],k = 0;
	for(i = 1;i < size;i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	
	int b[max + 1];
	for(i = 0;i < max + 1 ; i++)
	{
		b[i] = 0; 
	}
	for(i = 0 ; i < size ; i++)
	{
		b[arr[i]]++;
	}
	for(i = 0,k = 0;i < size;i++)
	{
		while(b[arr[i]] > 0)
		{				//even though here there are 2 loops. the complexity is still O(n)..
			c[k++] = arr[i];
			b[arr[i]]--;
		}
	}
	for(i = 0 ; i < size;i++)
	{
		arr[i] = c[i];
	}
	
}





























