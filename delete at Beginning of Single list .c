#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*temp,*newnode,*head,*last;

void created() 
{
int d;
do{
printf("\n Enter a value : \n");
scanf("%d",&d);
newnode=malloc(sizeof(struct node));
newnode->data=d;
newnode->next=NULL;
if(head==NULL) 
{
head=newnode;
last=newnode;
}
else
{
last->next=newnode;
last=newnode;
}
}while(d!=999);
}
void pri() 
{
temp=head;
printf("After Delection :\n ");
while(temp!=NULL)
{
printf("%d",temp->data);
temp=temp->next;
}
}
void delete () 
{
if(head==NULL){
printf("list is empty");
}

else{

temp=head;
head=temp->next;
free(temp);
}
}
int main()

{
printf("If you want to end the values enter the number is 999");
created();
delete();
pri();
return 0;
}
    