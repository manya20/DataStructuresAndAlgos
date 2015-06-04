#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Hashtable
{
	int tableSize;
	char arr[300000][20];
};

typedef struct Hashtable htable;

int hashFun(char[]);
void initialize(htable*);
void insert(htable*,char str[]);
void search(htable*,char str[]);
void shuffle(char str[]);
void randomString(htable*);
static int score = 0;

main()
{
	htable *ht = (htable*) malloc(sizeof(htable));
	if(ht == NULL)
	{
		printf("Error");
		return;
	}
	printf("allocated\n");
	FILE *fp;
	fp = fopen("/home/mohit/study stuff/Hashing/Wordlist.txt","r");
	srand(time(NULL));
	initialize(ht);
	char str[15];
	clock_t c1 = clock();
	while(fscanf(fp,"%s",str) != EOF)
	{
		insert(ht,str);
		//printf("sdssd\n");
	}
	clock_t c2 = clock();
	printf("\n\n%f",(float) (c2 - c1) / CLOCKS_PER_SEC);
	fclose(fp);
	printf("done\n");
	while(1)
	{
		/*printf("Enter the string to search for\n");
		scanf("%s",str);
		if(strcmp(str,"null") == 0)
			break;
		else
			search(ht,str);*/
		randomString(ht);
		scanf("%s",str);
		if(strcmp(str,"null") == 0)
			break;
		else
			search(ht,str);
		/*randomString(ht);
		printf(" Enter your string\n");
		scanf("%s",str);
		search(ht,str);*/
	}
	//printf("%s  %s\n",ht->arr[45],ht->arr[1000]);
}

void initialize(htable *ht)
{
	ht->tableSize = 300000;
	int i = 0;
	for(i = 0 ;i < 300000;i++)
	{
		//ht->arr[i][0] = "null";
		strcpy(*(ht->arr + i) + 0,"null");
	}
}

int hashFun(char str[])
{
	int length = strlen(str);
	char *ptr = str;
	int sum = 0;
	while(*ptr != '\0')
	{
		sum = sum + (int)*ptr;
		ptr++;
	}
	//printf("%d\n",sum % 100);
	return sum;
}

void insert(htable *ht,char str[])
{
	int index = hashFun(str);
	int collision = 0;
	if(strcmp(*(ht->arr + index) + 0,"null") == 0)
	{
		strcpy(*(ht->arr + index) + 0,str);
		//printf("Entered in first\n");
		return;
	}
	else
	{
		while(strcmp(*(ht->arr + index) + 0,"null") != 0)
		{
			index = index + 2 * ++collision - 1;
			if(index >= ht->tableSize)
				index = index - ht->tableSize;
		}

		strcpy(*(ht->arr + index) + 0,str);
		//printf("Entered in second\n");
		return;
		
	}
}

void search(htable* ht,char str[])
{
	int index = hashFun(str);
	int collision = 0;
	if(strcmp(*(ht->arr + index) + 0,str) == 0)
	{	
		int length = strlen(*(ht->arr + index) + 0);
		score += length;
		printf("u scored: %d\n",length);
		printf("Total score: %d\n",score);
		//printf("Its is der\n");
		//printf("Entered in first\n");
		return;
	}
	
	else
	{
		while(strcmp(*(ht->arr + index) + 0,"null") != 0 && strcmp(*(ht->arr + index) + 0,str) != 0)
		{
			index = index + 2 * ++collision - 1;
			if(index >= ht->tableSize)
				index = index - ht->tableSize;
		}

		if(strcmp(*(ht->arr + index) + 0,str) == 0)
		{
			//printf("its der\n");
			int length = strlen(*(ht->arr + index) + 0);
			score += length;
			printf("u scored: %d\n",length);
			printf("Total score: %d\n",score);
			return;
		}
		else
		{
			//printf("its not\n");
			printf("u scored: %d\n",0);
			printf("Total score: %d\n",score);
		}
		//printf("Entered in second\n");
		return;
		
	}
}

void shuffle(char str[])
{
	int length = strlen(str);
	int i;
	char arr[length];
	char temp;
	strcpy(arr,str);
	srand(time(NULL));
	for(i = length -1; i > 0;i--)
	{
		int random = rand() % (1 + i);
		temp = arr[i];
		arr[i] = arr[random];
		arr[random] = temp;
		
	}
	//printf("Shuffle called");
	printf("%s\n",arr);
}

void randomString(htable *ht)
{	
	srand(time(NULL));
	
	while(1)
	{	
		int index = rand() % 300000;
		if(strcmp(*(ht->arr + index) + 0,"null") == 0)
			continue;
		else if(strlen(*(ht->arr + index) + 0 ) < 7)
			continue;
		else
		{
			shuffle(*(ht->arr + index) + 0) ;
			break;
		}
	}
}

