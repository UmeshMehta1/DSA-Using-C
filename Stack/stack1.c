#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10

int stack[MAXSIZE], top=-1;

// int push(),pop(), display();

main(){
    int choice;

    do{
        printf("\n================Stack Menu================");
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit");
        printf("\n==============================================");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        

        switch (choice)
        {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: display();break;
        case 5: temp();break;

        }
    }while (choice!=4);

   return 0;
    
}

   push(){
    int n;
    if(top==MAXSIZE-1)
      printf("\nStack is overflow");
      else
        printf("\nEnter an element: ");
        scanf("%d",&n);
        top++;
        stack[top]=n;
      
        

    }

    pop(){
        int n;
       if(top==-1)
          printf("\nStack is empty");
      else
        n=stack[top];
        top--;
        printf("\n Poped emement is %d",n);

    }

    display(){
        int i;
        if(top==-1)
          printf("\nStack is empty.");
        else
          printf("\nElement of stack.");
          for(i=top;i>=0;i--)
            printf("\n%d", stack[i]);
    } 

    temp(){
        int i;
        for(i=0;i<5;i++)
          printf("\n%d",stack[i]);
    }