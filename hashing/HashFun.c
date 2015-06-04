#include<stdio.h>
#include<string.h>

void hashFun(char[]);

main()
{
	char str[10];
	while(1)
	{
		printf("Enter the string..\n");
		scanf("%s",str);
		if(strcmp(str,"NULL") == 0)
		break;
		else
		hashFun(str);
	}
}

void hashFun(char str[])
{
	int length = strlen(str);
	char *ptr = str;
	int sum = 0;
	while(*ptr != '\0')
	{
		sum = sum + (int)*ptr;
		ptr++;
	}
	printf("%d\n",sum % 100);
}
