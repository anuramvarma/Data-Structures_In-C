#include<stdio.h>
#include<stdlib.h>
struct node
 {
  int data;
  struct node*next;
 };

void create_node(struct node **tail,int d)
{
struct node *temp=(struct node*)malloc(sizeof(struct node*));
temp->data=d;
temp->next=temp;
(*tail)=temp;
}

 void display(struct node*tail)
{
  struct node*ptr=tail->next;
  do
  {
   printf("%d ",ptr->data);
   ptr=ptr->next;
  }
    while(ptr!=tail->next);
}

//This function is need to be in code for output of delete operation,because of insufficient Nodes//
   void insert_at_position(struct node*tail,int pos,int d)
{
    struct node*temp=malloc(sizeof(struct node*));
      temp->data=d;
      temp->next=NULL;
    struct node*ptr=tail->next;
        pos--;
  while(pos>1)
    {
      ptr=ptr->next;
      pos--;
    }
       temp->next=ptr->next;
       ptr->next=temp;
}

   void delete_at_beginning(struct node**tail)
 {
     struct node*ptr=(*tail)->next;
      (*tail)->next=ptr->next;
       free(ptr);
    if(ptr==(*tail))
      {
        free(ptr);
        (*tail)=NULL;
      }
}

int main()
{
   struct node*tail=NULL;
   tail=(struct node*)malloc(sizeof(struct node*));
   create_node(&tail,10);
   display(tail);

printf("\n");
  insert_at_position(tail,2,60);
  display(tail);
printf("\nDELETE AT BEGINNING\n");
  delete_at_beginning(&tail);
  display(tail);

}
