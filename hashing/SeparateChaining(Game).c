#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct Node
{
	 char data[20];
	struct Node *next;
};

typedef struct Node node;

struct HashTable
{
	int size;
	node *list[100];
};

typedef struct HashTable htable;

int hashFun(char[]);
void initialize(htable*);
void insert(htable*,char str[]);
void search(htable*,char str[]);
void shuffle(char str[]);
void randomString(htable*);
static int score = 0;
//char* ret
main()
{	
	FILE *fp;
	fp = fopen("/home/mohit/study stuff/Hashing/Wordlist.txt","r");
	srand(time(NULL));
	htable ht;
	initialize(&ht);
	int i = 0;
	char data[20];
	//char *arr[10];
	
	/*for(i = 0; i < 100 ; i++)
	{
		if(ht.list[i] == NULL)
			printf("it is null\n");
		else
			printf("it is not\n");
	}*/	
	clock_t c1 = clock();
	while(fscanf(fp,"%s",data) != EOF)
	{

		insert(&ht,data);
	}
	clock_t c2 = clock();
	printf("\n\n%f",(float) (c2 - c1) / CLOCKS_PER_SEC);
	fclose(fp);
	printf("done");
	
	while(1)
	{
		randomString(&ht);
		printf(" Enter your string\n");
		scanf("%s",data);
		search(&ht,data);
	}
	//printf("\n%s",ht.list[45]->data);
	/*while(1)
	{
		printf("Enter the string to search for\n");
		scanf("%s",data);
		if(strcmp(data,"null") == 0)
			break;
		else
			search(&ht,data);
	}*/
	//ht.list[45] = (node*) malloc(sizeof(node));
	//ht.list[45]->data = "mohit";
	
	//printf("\n%s",ht.list[45]->data);
//	while()
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
	return sum % 100;
}

void initialize(htable *ht)
{
	
	ht->size = 100;
	int i;
	for(i = 0;i < 100;i++)
	{
		ht->list[i] = NULL;
              
	}

       // return ht;
}

void insert(htable *ht,char str[])
{
	int index = hashFun(str);
	if(ht->list[index] == NULL)
	{
		ht->list[index] = (node*) malloc(sizeof(node));
		strcpy(ht->list[index]->data,str);
		ht->list[index]->next = NULL;
		//printf("Entered in first\n");
		return;
	}
	
	{	
		node *temp = ht->list[index];
		/*while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = (node*) malloc(sizeof(node));
		temp = temp->next;
		strcpy(temp->data,str);
		temp->next = NULL;*/
		ht->list[index] = (node*) malloc(sizeof(node));
		strcpy(ht->list[index]->data,str);
		ht->list[index]->next = temp;
		//printf("Entered in later sections\n");
		return;
	}
	
}

void search(htable *ht,char str[])
{
	int index = hashFun(str);
	if(ht->list[index] == NULL)
	{
		printf("not in the table\n");
		return;
	}
	else if(strcmp(str,ht->list[index]->data) == 0)
	{	
		int length = strlen(str);
		//printf("The word is at index %d",index);
		score += length;
		printf("Points awarded:%d\n",length);
		printf("Total score:%d\n",score);
		return;
	}
	else
	{
		node *temp=ht->list[index];
		while(temp != NULL && strcmp(str,temp->data) != 0)
			temp = temp->next;
		if(temp == NULL)
		{	
			int length = strlen(str); 
			//printf("not in the table\n");
			printf("Points awarded:%d\n",length);
			printf("Total score:%d\n",score);
			return;
		}
		else
		{
			//printf("The word is at index %d",index);
			printf("Points awarded:%d\n",0);
			printf("Total score:%d\n",score);
			return;
		}
	}
}

void shuffle(char str[])
{
	int i, random, length = strlen(str);
    	char temp;
	char arr[20];
	strcpy(arr,str);
	
    for (i = length-1; i > 0; i--)
    {	
	
        random = rand()%(i+1);
        /*temp = str[random];
        arr[random] = arr[i];
        arr[i] = temp;*/
	temp = arr[i];
	arr[i] = arr[random];
	arr[random] = temp;
    }
	printf("\n%s\n%s",arr,str);
}

void randomString(htable *ht)
{
	int counter;
	while(1)
	{
		counter = rand() % 100;
		if(strlen(ht->list[counter]->data) >= 7)
		{
			shuffle(ht->list[counter]->data);
			break;
		}
		else
		{
			node *temp = ht->list[counter];
			while(temp != NULL && strlen(ht->list[counter]->data) != 7 )
				temp = temp->next;
			if(temp == NULL)
				continue;
			else
			{
				shuffle(temp->data);
				break;
			}
		}
	}
}
