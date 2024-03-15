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
void insert_at_beginning(struct node**head,int d);
void insert_at_beginning(struct node**head,int d)
{
	struct node*temp=malloc(sizeof(struct node*));
	temp->data=d;
	temp->next=NULL;
	temp->next=*head;
	*head=temp;
}

int main()
{
	struct node*head=NULL;
	head=(struct node*)malloc(sizeof(struct node*));
  create_node(&head,10);
	display(head);
	count_of_nodes(head);
  printf("\nInsert at begining: ");
	insert_at_beginning(&head,40);
	display(head);
}
