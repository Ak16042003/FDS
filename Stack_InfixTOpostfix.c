#include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<limits.h>

struct abc
{
    char data;
    struct abc *next;
};
struct abc *top=NULL;
void push(char);
char pop();
int precedence(char);

void main()
{
    char infix[20], postfix[20];
    int i=0, j=0;
    printf("Enter the infix expression: ");
    scanf("%s",infix);

    while(infix[i]!='\0')
    {
      if(isalnum(infix[i]))
      {
          postfix[j]=infix[i];
          j++;
      }
      else
      {
          if(top==NULL)
          {
            push(infix[i]);
          }
          else
          {
              while(precedence(infix[i]<=precedence(top->data) && top!=NULL))
              {
                  postfix[j]=pop();
                  j++;
              }
            push(infix[i]);
          }
      }
      i++;
    }
   
   while(top!=NULL)
   {
       postfix[j]=pop();
       j++;
   }
   postfix[j]='\0';
   printf("%s", postfix);
 }

int precedence(char op)
{
    switch(op)
    {
        case'^': return 3;
                 break;

        case'*': return 2;
                 break;
       
        case'/': return 2;
                 break;

        case'+': return 1;
                 break;

        case'-': return 1;
                 break;
        default: return 0;
    }
}

void push(char op)
{
    struct abc *new;
    new=(struct abc*)malloc(sizeof(struct abc));
    new->data=op;
    new->next=NULL;
    if(top==NULL)
    {
        top=new;
    }
    else
    {
        new->next=top;
        top=new;
    }
}

char pop()
{
   char op;
   struct abc *temp;

   if(top==NULL)
   {
      printf("Stack is empty");
   }
   else if(top->next=NULL)
   {
      temp=top;
      op=top->data;
      top=NULL;
      free(temp);
   }
   else//when there are more than 1 node
   {
      temp=top;
      op=top->data;
      top=top->next;
      free (temp);
   }
   
   
   
   return op;
} 