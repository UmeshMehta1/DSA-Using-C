#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct{
  char items[MAX];
  int tos;
}stack;

int isEmpty(stack*s)
{
  return s->tos==-1;
}

int isFull(stack*s)
{
  return s->tos==MAX-1;
}

void push(stack*s,char ch)
{
   if(isFull(s))
   {
      printf("Void insertion.");getch();exit(0);
   }
   s->items[++s->tos]=ch;
}
char pop(stack*s)
{
   if(isEmpty(s))
   {
      printf("Void deletion.");getch();exit(0);
   }
   return s->items[s->tos--];
}

char peek(stack*s)
{
   if(isEmpty(s))
   {
     printf("Void access.");getch();exit(0);
   }
   return s->items[s->tos];
}

int getPrecedence(char ch)
{
  switch(ch)
  {
    case '(': return 0;
    case '+':
    case '-': return 1;
    case '*':
    case '/':
    case '%': return 2;
    case '$': return 3;
    default: return -1;//this case never occurs
  }
}

void main()
{
  stack opstack,poststack;
  char infix[MAX],ch;
  int i;
  opstack.tos=poststack.tos=-1;//initialize both stack to empty
  
  printf("Enter your infix expression:");
  gets(infix);
  for(i=0;i<strlen(infix);i++)//read each symbol one by one from left to right
  {
     ch=infix[i];
     if(ch=='(')
       push(&opstack,ch);//push the opener into opstack
     else if(isalnum(ch))//push the operand into the poststack
       push(&poststack,ch);
     else if(ch==')')//if scan char is closing parenthesis
     {

       while(peek(&opstack)!='(')//see if opstack top contains opener
	 push(&poststack,pop(&opstack));//if not then pop and push into poststack
       pop(&opstack);//pop the opstack and discard the parentheses
     }
     else//if scan char is operator
     {

	while(!isEmpty(&opstack) && getPrecedence(peek(&opstack))>=getPrecedence(ch))//opstack top item is >= ch in precedance
	  push(&poststack,pop(&opstack));//pop opstack and push into poststack
	push(&opstack,ch);//finally push the scanned operator into opstack
     }
  }
  
  while(!isEmpty(&opstack))//until opstack become empty
    push(&poststack,pop(&opstack));//pop opstack and push into poststack
  //finally display the poststack content
  printf("\nInfix expression: %s",infix);
  printf("\nPostfix expression: ");
  for(i=0;i<=poststack.tos;i++)
    printf("%c",poststack.items[i]);
  getch();
}

