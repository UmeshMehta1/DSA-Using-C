#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *add;
};

struct node *start = NULL, *temp, *newNode, *next, *prev;

// Function prototypes
void create();
void Display();
void insert_First();
void insert_Last();
void insert_Middle();
void delete_First();
void delete_Last();
void delete_Middle();

int main()
{
    int choice;

    do
    {
        printf("\n================Linked List Menu================");
        printf("\n1. create\n2.insert_First \n3.insert_Last \n4.insert_Middle \n5.delete_First \n6.delete_Last \n7.delete_Middle \n8.Display \n9.Exit");
        printf("\n==============================================");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_First();
            break;
        case 3:
            insert_Last();
            break;
        case 4:
            insert_Middle();
            break;
        case 5:
            delete_First();
            break;
        case 6:
            delete_Last();
            break;
        case 7:
            delete_Middle();
            break;
        case 8:
            Display();
            break;
        case 9:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice! Please try again.");
        }
    } while (choice != 9);

    return 0;
}

void create()
{
    char ch;
    int n;
    printf("Enter an Element: ");
    scanf("%d", &n);
    start = (struct node *)(malloc(sizeof(struct node)));

    start->data = n;
    start->add = NULL;
    temp = start;

    printf("Want to Continue (y/n): ");
    ch = getche();

    while (ch == 'y' || ch == 'Y')
    {
        printf("\nEnter Next Element: ");
        scanf("%d", &n);

        newNode = (struct node *)(malloc(sizeof(struct node)));

        newNode->data = n;
        newNode->add = NULL;
        temp->add = newNode;
        temp = newNode; // Move temp to the new node
        printf("Want to Continue (y/n): ");
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

// Insert first in Linkedlist
void insert_First()
{
    int n;
    printf("Enter New Element to insert: ");
    scanf("%d", &n);
    newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->data = n;
    newNode->add = start;
    start = newNode;
}

// insert last in LinkedList
void insert_Last()
{
    int n;
    printf("Enter New Element to insert: ");
    scanf("%d", &n);
    newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->data = n;
    newNode->add = NULL;
    temp = start;

    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        while (temp->add != NULL)
        {
            temp = temp->add;
        }
        temp->add = newNode;
    }
}

// Insert Last in LinkedList..
void insert_Middle()
{
    int n, pos, i = 1;
    if (start == NULL)
    {
        printf("List Not Found..");
    }
    else
    {
        printf("Enter New Element to insert: ");
        scanf("%d", &n);
        newNode = (struct node *)(malloc(sizeof(struct node)));
        newNode->data = n;
        newNode->add = NULL;

        printf("Enter the position: ");
        scanf("%d", &pos);

        if (pos == 1)
        {
            newNode->add = start;
            start = newNode;
            return;
        }

        temp = start;
        while (i < pos - 1 && temp->add != NULL)
        {
            temp = temp->add;
            i++;
        }

        if (temp->add == NULL)
        {
            temp->add = newNode;
        }
        else
        {
            newNode->add = temp->add;
            temp->add = newNode;
        }
    }
}

// delete first from linklist;
void delete_First()
{
    if (start == NULL)
    {
        printf("List Not Found..");
    }
    else
    {
        temp = start;
        start = start->add;
        printf("Deleted node is %d", temp->data);
        free(temp);
    }
}

// Deleted Last Node from linkelist;
void delete_Last()
{
    if (start == NULL)
    {
        printf("List Not Found..");
    }
    else
    {
        temp = start;

        if (temp->add == NULL)
        {
            printf("Deleted Node %d", temp->data);
            free(temp);
            start = NULL;
        }
        else
        {
            while (temp->add != NULL)
            {
                prev = temp;
                temp = temp->add;
            }
            prev->add = NULL;
            printf("Deleted Node %d", temp->data);
            free(temp);
        }
    }
}

void delete_Middle()
{
    int pos, i = 1;

    if (start == NULL)
    {
        printf("List Not Found..");
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &pos);

        if (pos == 1)
        {
            temp = start;
            start = start->add;
            printf("Deleted node: %d", temp->data);
            free(temp);
            return;
        }

        temp = start;
        while (i < pos && temp->add != NULL)
        {
            prev = temp;
            temp = temp->add;
            i++;
        }

        if (temp->add == NULL)
        {
            printf("Position not found.");
        }
        else
        {
            next = temp->add;
            prev->add = next;
            printf("Deleted node: %d", temp->data);
            free(temp);
        }
    }
}
