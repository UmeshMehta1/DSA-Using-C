#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *add;
};

struct node *start = NULL, *temp, *newNode;

int main()
{

    int choice;

    do
    {
        printf("\n================Linked List Menu================");
        printf("\n1. create\n2.insertOnFirst \n3.insertOnLast \n4.insertOnLastMiddle \n5.deleteFromFirst \n6.deleteFromLast \n7.deleteFromMiddle \n8.Display \n9.Exit");
        printf("\n==============================================");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        // case 2:
        //     insertOnFirst();
        //     break;
        // case 3:
        //     insertOnLast();
        //     break;
        // case 4:
        //     insertOnLastMiddle();
        //     break;
        // case 5:
        //     deleteFromFirst();
        //     break;
        // case 6:
        //     deleteFromLast();
        //     break;
        // case 7:
        //     deleteFromMiddle();
        //     break;
        case 8:
            Display();
            break;
            // case 9:
            //     Exit();
            //     break;
        }
    } while (choice != 9);

    return 0;
}

void create()
{
    char ch;
    int n;
    printf("Enter an Element.");
    scanf("%d", &n);
    start = (struct node *)(malloc(sizeof(struct node)));

    start->data = n;
    start->add = NULL;
    temp = start;

    printf("Want to Continue..");
    ch = getche();

    while (ch == 'y' || ch == 'Y')
    {
        printf("Enter Next Element: ");
        scanf("%d", &n);

        newNode = (struct node *)(malloc(sizeof(struct node)));

        newNode->data = n;
        newNode->add = NULL;
        temp->add = newNode;
        printf("want to Contiue....");
        ch = getche();
    }
}

void Display()
{
    if (start == NULL)
    {
        printf("List is Not Found...");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("\t%d", temp->data);
            temp = temp->add;
        }
    }
}