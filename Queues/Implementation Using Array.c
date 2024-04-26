// C Program to Implement a Queue using an Array
#include <stdio.h>
#include<stdlib.h>
#define MAX 100
void insert();
void delete();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int choice;
    while (1)
    {
	printf("Choose Your Choice to perform Operation");
	printf("\n-------------------------------------------");
        printf("\n1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n\n");
        printf("Enter your choice : ");
	         scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n Choose between 1-4\n");
        } 
    } 
} 

void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("\nQueue Overflow \n\n");
    else
    {
        if (front == -1) 
            front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} 

void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} 

void display()
{
    int i;
    if (front==rear)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front;i <= rear;i++)
            printf("%d ",queue_array[i]);
        printf("\n");
    }
} 
