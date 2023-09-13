#include<stdio.h>
#include<stdlib.h>

#define N 100			//defining the size of queue

int s[N], top = -1;

int pop ()				//function to remove an element from stack
{
  return s[top--];
}

void push (int x)			//function to insert an element into stack
{
  if (top == N - 1)
    printf ("Stack is Full");
  else
    {
      top++;
      s[top] = x;
    }
}

void enqueue (int x)
{
  push (x);
}

void display ()			//function to print elements of a queue
{
  int i;
  for (i = 0; i <= top; i++)
    printf (" %d ", s[i]);
}

int dequeue ()
{
  int data, res;
  if (top == -1)
    printf ("Queue is Empty");
  else if (top == 0)
    return pop ();
  data = pop ();
  res = dequeue ();
  push (data);
  return res;

}

int main ()
{
    int item,choice;
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
 display();
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


