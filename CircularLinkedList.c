#include<stdio.h>
#include<stdlib.h>
struct node
  {
   int data;
   struct node*next;
  };
  void create_node(struct node**tail,int d);
  void create_node(struct node**tail,int d)
  {
    struct node*temp=malloc(sizeof(struct node*));
     temp->data=d;
     temp->next=temp;
     (*tail)=temp;
  }
  
  void display(struct node*tail);
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
  
  
  void insert_at_beginning(struct node*tail,int d);
  void insert_at_beginning(struct node*tail,int d)
    {
      struct node*temp=malloc(sizeof(struct node*));
        temp->data=d;
        temp->next=NULL;
        temp->next=tail->next;
        tail->next=temp;
    } 
    
    
   void insert_at_end(struct node**tail,int d);
   void insert_at_end(struct node**tail,int d)
    {
     struct node*temp=malloc(sizeof(struct node*));
      temp->data=d;
      temp->next=NULL; 
      temp->next=(*tail)->next;
       (*tail)->next=temp;
       (*tail)=temp;
    }
    
    
   void insert_at_position(struct node**tail,int d,int pos);
   void insert_at_position(struct node**tail,int d,int pos)
{
      struct node*temp=malloc(sizeof(struct node*));
        temp->data=d;
        temp->next=NULL;
      struct node*ptr=(*tail)->next;
         pos--;
      while(pos>1)
   {
       ptr=ptr->next;
       pos--;
   }
      temp->next=ptr->next;
      ptr->next=temp;
}


  void delete_at_beginning(struct node*tail);
  void delete_at_beginning(struct node*tail)
{
       struct node*ptr=tail->next;
         tail->next=ptr->next;
          free(ptr);
         ptr=NULL;
       if(tail->next==tail)
        { 
         free(ptr);
         tail=NULL;
        }
}

int main()
{
   struct node*tail=NULL;
      create_node(&tail,10);
      display(tail);
   printf("\ninsert at beginning\n");
     insert_at_beginning(tail,20);
     display(tail);
   printf("\ninsert_at_end\n");
     insert_at_end(&tail,40);
     display(tail);
   printf("\ninsert_at_position\n");
      insert_at_position(&tail,60,2);
      display(tail);
   printf("\ndelete_at_beginning\n");
     delete_at_beginning(tail);
     display(tail);
   printf("\n");
}
