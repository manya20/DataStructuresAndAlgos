#include<stdio.h>
#include<stdlib.h>
struct Node{
     int data;
     struct Node* next;
    };
typedef struct Node node;
struct Node* head;
void Print();
node* Delete(int n);
void Insert(int x);
void Insert(int x){
      struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
      temp->data =x;
      temp->next=head;
      head=temp;
      /*temp->next =NULL;
      if(head! =NULL){
      temp->next =head;
      head =temp;*/
      }
void Print(){
      while(head)
	{
		printf("\n%d",head->data);
                head=head->next;
                Print();
	}
    }

 node* Delete(int n){ 
     struct Node* temp1 =(struct Node*)malloc(sizeof(struct Node));
     temp1=head;
      
    if(n==1){
          head=temp1->next;
          free(temp1);
           return;}
      int j;
    for(j=0;j<n-2;j++){
       printf("CB");
           temp1=temp1->next;}
      struct Node* temp2 =(struct Node*)malloc(sizeof(struct Node));
      temp2=temp1->next;
      temp1->next=temp2->next;
     free(temp2);
     return(head);
   }
     void main(){
    head = NULL;
    struct Node* temp3; //empty
    
    int m,i,x,v,n;
    printf("How many numbes \n");
    scanf("%d",&m);
    for(i=0;i<m;i++){
          printf("Enter the number \n");
	//printf("cat");
          scanf("%d",&x);
	
          Insert(x);
          //printf("cat");
      }Print();
   printf("Which node want to delete \n");
   scanf("%d",&v);
   printf("CB");

   temp3=Delete(v);
  printf("CB");
   Print();}
  

