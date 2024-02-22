#include<stdio.h>
// #include<conio.h>
#define MAXSIZE 10
int queue1[MAXSIZE], rare=-1,front=-1;

int main(){
    int choice;

    do{
        printf("\n====Circular queue Implementatin==========\n");
        printf("\n1.Insert\n2.Delete\n3.Display\n");

        printf("\n====================================\n");

        printf("\nChoice the Element: ");
        scanf("%d",&choice);

        printf("\n===================================\n");

        switch (choice)
        {
        case 1:insert();break;
        case 2:delete1();break;
        case 3:display();break;
        }

    }while(choice!=4);

    return 0;
}

int insert(){
    int n;
    if((rare+1)%MAXSIZE==front){
        printf("Queue is overflow");
    }else{
            printf("enter the element: ");
            scanf("%d",&n);

            if(rare ==-1 && front== -1){
                rare=0; 
                front=0;

            }else{
                rare=(rare+1)%MAXSIZE;

                queue1[rare]=n;
            }
    }

}

int delete1(){
   int n;
   if(rare== -1 && front == -1){
    printf("queue is empty");
   }else{
    n=queue1[front];

    if(rare==front){
        rare = -1;
        front= -1;
    }else{
        front= (front+1)%MAXSIZE;
        printf("%d element is deleted.",n);
    }
   }
}

int display(){
   int i;
   if(rare== -1 && front == -1){
    printf("queue is empty");
   }else{
    printf("\nThe Elements of queue's are: ");
     for(i=front;i!=rare;(i=(i+1)%MAXSIZE)){
        printf("%5d",queue1[i]);
     }
   }
}