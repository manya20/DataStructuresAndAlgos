#include<stdio.h>
#include<string.h>

void encoding(char str[],int size);

main()
{
	char str[50];
	printf("Enter the string\n");
	scanf("%s",str);
	int size = strlen(str);
	encoding(str,size);
}


void encoding(char str[],int size)
{
	char *b = (char*)malloc(sizeof(str) - 1); //i m doing minus 1.. becoz it was the added condition in microsoft interview. the max
						  // length of encoded string can be size - 1 of original string..

	int i = 0, j = 0, count;
	while(j < size - 1)
	{
		//printf("inside\n");
		if(i >= size)
		{
			break;
		}
		else
		{
			count = 1;
			b[j++] = str[i];
			while(str[i + 1] == str[i])
			{
				count++;
				i++;
			}
			i++;
			b[j++] = count + '0';
		}
	}
	if(j == (size - 1))
	{
		printf("the encoded string had length greater the the Original size - 1\n");
		return;
	}
	else
	{
		printf("here\n");
		strcpy(str,b);
		printf("%s\n",str);
	}

}




























