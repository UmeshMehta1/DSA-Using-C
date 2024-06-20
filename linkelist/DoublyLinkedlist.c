#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void create();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *temp, *newNode, *temp;

int main()
{
    int choice;

    do
    {
        printf("\n================Linked List Menu================");
        printf("\n1. create\n2.insert_First \n3.insert_Last \n4.insert_Middle \n5.delete_First \n6.delete_Last \n7.delete_Middle \n8.Display \n9.Exit \n10. Count Node");
        printf("\n==============================================");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        // case 2:
        //     insert_First();
        //     break;
        // case 3:
        //     insert_Last();
        //     break;
        // case 4:
        //     insert_Middle();
        //     break;
        // case 5:
        //     delete_First();
        //     break;
        // case 6:
        //     delete_Last();
        //     break;
        // case 7:
        //     delete_Middle();
        //     break;
        case 8:
            Display();
            break;
        case 9:
            printf("Exiting...");
            break;

        // case 10:
        //     countNode();
        //     break;
        // case 11:
        //     countNode();
        //     break;
        default:
            printf("Invalid choice! Please try again.");
        }
    } while (choice != 9);

    return 0;
}

void create()
{
    head = 0;
    int choice = 1;

    while (choice)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &newNode->data);
        newNode->prev = 0;
        newNode->next = 0;
        if (head == 0)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
        printf("Do you want to continue");
        scanf("%d", &choice);
    }
}

void Display()
{
    if (head == NULL)
    {
        printf("List is Not Found...");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
    }
}
