#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *add;
};

struct node *start = NULL, *temp, *newNode, *next, *prev;

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
            Exit();
            break;
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

// Insert first in Linkedlist
void insert_First()
{
    int n;
    if (start == NULL)
    {
        printf("list Not Found..");
    }
    else
    {
        printf("Enter NewElement for insert..");
        scanf("%d", &n);
        newNode = (struct node *)(malloc(sizeof(struct node)));
        newNode->data = n;
        newNode->add = NULL;
        newNode->add = start;
        start = newNode;
    }
}

// insert last in LinkedList
void insert_Last()
{
    int n;
    if (start == NULL)
    {
        printf("list Not Found..");
    }
    else
    {
        printf("Enter NewElement for insert..");
        scanf("%d", &n);
        newNode = (struct node *)(malloc(sizeof(struct node)));
        newNode->data = n;
        newNode->add = NULL;
        temp = start;

        while (temp->add != NULL)
        {
            temp = temp->add;
            temp++;
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
        printf("list Not Found..");
    }
    else
    {
        printf("Enter NewElement for insert..");
        scanf("%d", &n);
        newNode = (struct node *)(malloc(sizeof(struct node)));
        newNode->data = n;
        newNode->add = NULL;

        printf("Enter the position: ");
        scanf("\t %d", &pos);

        while (i < pos)
        {
            prev = next;
            next = next->add;
            i++;
        }
        prev->add = newNode;
        newNode->add = next;
    }
}