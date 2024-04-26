#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   
void insert();  
void delete();  
void display();  
void main()  
{  
    int choice;   
    while(choice != 4)   
    {     
        printf("\nChoose Your Choice to perform Operation \n");           
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice :");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:insert();               
              break;  
              
            case 2:delete();              
              break; 
               
            case 3:display();             
              break; 
               
            case 4:exit(0);                
              break; 
               
            default:   
            printf("\nEnter valid choice b/w 1-4\n");  
        }  
    }  
}  
void insert()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nQueue is OVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value to insert :\n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void delete()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nQueue is UNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nQueue is Empty\n");  
    }  
    else  
    {   printf("\nThe values are: ");  
        while(ptr != NULL)   
        {  
            printf("%d  ",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  
