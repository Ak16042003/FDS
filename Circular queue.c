#include<stdio.h>

#define size 4
int queue[size], front = -1, rear = -1;

void
enqueue () //insertion happens from rear
{
  int data;

  if (rear == size - 1 && front == 0 || front == (rear + 1) % size)
    {
      printf ("overflow\n");
      return;
    }

  printf ("enter data:\n");
  scanf ("%d", &data);

  if (rear == size - 1)
    {
      rear = (rear + 1) % size;
    }

  else if (rear == -1)
    {
      rear = 0;
      front = 0;
    }
  else
    {
      rear = rear + 1;
    }

  queue[rear] = data;
}


void
dequeue ()
{
  int del;

  if (front == -1)
    {
      printf ("underflow\n");
      return;               // we dont want to print any garbage value....so we return from function
    }
  else
    {
      del = queue[front];

      if (front == rear)
{
 front = -1;
 rear = -1;
}

      else if (front == size - 1) // to delete the last element,,means front is at last position bc deletion always occurs from front
{
 front = (front + 1) % size; //if we did front++ then front would have become 5
}

      else
{
 front = front + 1;
}

    }

  printf ("deleted element is %d\n", del);
}

void
display ()
{
  int i;
    if(front == -1)                 // when array is empty
    {
        printf("empty queue\n");
    }
  if (front == rear)
    {
      printf ("%d", queue[rear]);
    }

  else if (front < rear)
    {
      for (i = front; i <= rear; i++)
{
 printf ("%d ", queue[i]);
}
    }

  else
    {
      for (i = front; i != rear + 1; i = (i + 1) % size)
{
 printf ("%d ", queue[i]);
}
    }

  printf ("\n");
}

void
main ()
{
  int ch;
  do
    {

      printf ("Enter choice:\n\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.exit\n\n");
      scanf ("%d", &ch);

      switch (ch)
{
case 1:
 enqueue ();
 break;

case 2:
 dequeue ();
 break;

case 3:
 display ();
 break;

case 4:
 printf ("thankyou\n");
 break;

default:
 printf ("enter valid choice\n");
}
    }
  while (ch != 4);
}