#include <stdio.h>
#include <stdlib.h>
#define max 100
int choice, item;
int front=-1,rear=-1;
int queue[max];

void enqueue(int item)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=item;
    }

    else if((rear+1)%max==front)
    {
        printf("Stack overflow\n");
    }
    else
    {
        rear=rear+1%max;
        queue[rear]=item;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue underflow\n");
    }
    else if(front == rear)
    {
        printf("Dequeued element is :%d",queue[front]);
        front=rear=-1;

    }

    else
    {
        printf("Dequeued element is :%d",queue[front]);
        front=(front+1)%max;
    }
}

void display()
{
    printf("Queue:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d",queue[i]);
    }
    printf("\n");
}




int main()
{


 while (1) {
 printf("\n1. Insert an element\n");
 printf("2. Delete an element\n");
 printf("3. Display the queue\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the element to insert: ");
 scanf("%d", &item);
 enqueue(item);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 display(queue);
 break;
 case 4:
 printf("Exiting the program.\n");
 return 0;
 default:
 printf("Invalid choice! Please try again.\n");
 }
 }
    return 0;

}
