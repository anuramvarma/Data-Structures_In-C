#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
void create_node(struct node**head,int d);
void create_node(struct node**head,int d){
	struct node*temp=malloc(sizeof(struct node*));
	temp->data=d;
	temp->next=NULL;
	*head=temp;
}

void display(struct node*head);
void display(struct node*head)
{
	struct node*ptr=head;
	while(ptr!=NULL)
	{
	printf("%d ",ptr->data);
	ptr=ptr->next;
	}
}
int count_of_nodes(struct node*head);
int count_of_nodes(struct node*head)
{
	int count=0;
struct node*ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	
	printf("\nNumber of Nodes = %d",count);	
}

  void insert_at_position(struct node*head,int d,int pos);
  void insert_at_position(struct node*head,int d,int pos)
{
	struct node*temp=malloc(sizeof(struct node*));
	temp->data=d;
	temp->next=NULL;
	struct node*ptr=head;
	pos--;
	while(pos!=1)
	{
		ptr=ptr->next;
		pos--;
	}
	     temp->next=ptr->next;
	     ptr->next=temp;
}
void delete_at_beginning(struct node**head);
void delete_at_beginning(struct node**head)
{
struct node *ptr=*head;
(*head)=(*head)->next;
free(ptr);

}

int main()
{
	struct node*head=NULL;
	head=(struct node*)malloc(sizeof(struct node*));
    create_node(&head,10);
	display(head);
	count_of_nodes(head);

    printf("\n");
	insert_at_position(head,60,2);
	display(head);
    printf("\nDeleted at begining: ");
	delete_at_beginning(&head);
	display(head);
 	
}
