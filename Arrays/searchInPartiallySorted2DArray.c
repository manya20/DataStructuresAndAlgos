#include<stdio.h>
#include<stdlib.h>


//in the 2D array..all the rows are sorted. and all the columns are sorted.
//no continuation of sorting in assumend between any 2 rows or columns.


void search(int **arr,int row,int col,int data);


main()
{
	int i,j,row,col,count = 0,data;
	int arr[10][10];
	printf("Enter the number of rows and columns\n");
	scanf("%d%d",&row,&col);
	i = j = 0;
	printf("Enter the numbers carefully such that each row and each column is sorted\n");
	while(count < row * col)
	{
		scanf("%d\n",&data);
		arr[i][j++] = data;
		if(j == row)
		{
			j = 0;
			i++;
		}
		
		count++;
	}
	search(arr[0],row,col,data);
}

void search(int **arr,int row,int col,int data)
{
	int i = 0, j = col - 1;
	while(i < row && j >= 0)
	{
		if(arr[i][j] == data)
		{
			printf("data is at row = %d and column = %d\n",row,col);
			return;
		}
		else if(arr[i][j] > data)
			j--;
		else 
			i++;
	}
	printf("data is not there in the array\n");
}



















































