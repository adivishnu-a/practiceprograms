#include <stdio.h>
#define SIZE 10

void enQueue(int);
void deQueue();
void display();

int items[SIZE], front = 0, rear = -1;

int main() 
{
   deQueue();

   enQueue(10);
   enQueue(20);
   enQueue(30);
   enQueue(40);
   enQueue(50);
   enQueue(60);

   display();

   deQueue();

   display();

   return 0;
}

void enQueue(int value) 
{
   if (rear == SIZE - 1)
   {
      printf("\nQueue is Full");
   }
   else 
   {
      if (front == -1)
         front = 0;
      rear++;
      items[rear] = value;
      printf("\nInserted : %d", value);
   }
}

void deQueue() 
{
   if (front == -1)
   {
      printf("\nQueue is Empty");
   }
   else 
   {
      printf("\nDeleted : %d", items[front]);
      front++;
      if (front > rear)
         front = rear = -1;
   }
}


void display() 
{
   if (rear == -1)
   {
      printf("\nQueue is Empty");
   }
   else 
   {
      int i;
      printf("\n\nQueue elements are:\n");
      for (i = front; i <= rear; i++)
      {
         printf("%d   ", items[i]);
      }
   }
   printf("\n");
}
