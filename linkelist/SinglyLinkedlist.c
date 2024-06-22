#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node
{
    int data;
    struct node *add;
};

// Global variables
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
void countNode();
void searchNode();

int main()
{
    int choice;

    do
    {
        printf("\n================Linked List Menu================");
        printf("\n1. Create\n2. Insert_First\n3. Insert_Last\n4. Insert_Middle\n5. Delete_First\n6. Delete_Last\n7. Delete_Middle\n8. Display\n9. Exit\n10. Count Node\n11. Search Node");
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
            printf("Exiting...\n");
            break;
        case 10:
            countNode();
            break;
        case 11:
            searchNode();
            break;
        default:
            printf("Invalid choice! Please try again.\n");
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
    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->add = NULL;
    temp = start;

    printf("Want to Continue (y/n): ");
    while ((ch = getchar()) != '\n' && ch != EOF)
        ; // clear the input buffer
    ch = getchar();

    while (ch == 'y' || ch == 'Y')
    {
        printf("Enter Next Element: ");
        scanf("%d", &n);
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = n;
        newNode->add = NULL;
        temp->add = newNode;
        temp = newNode; // Move temp to the new node
        printf("Want to Continue (y/n): ");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ; // clear the input buffer
        ch = getchar();
    }
}

void Display()
{
    if (start == NULL)
    {
        printf("List is Not Found...\n");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("\t%d", temp->data);
            temp = temp->add;
        }
        printf("\n");
    }
}

// Insert first in Linkedlist
void insert_First()
{
    int n;
    printf("Enter New Element to insert: ");
    scanf("%d", &n);
    newNode = (struct node *)malloc(sizeof(struct node));
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
    newNode = (struct node *)malloc(sizeof(struct node));
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

// Insert in the middle of the LinkedList
void insert_Middle()
{
    int n, pos, i = 1;
    if (start == NULL)
    {
        printf("List Not Found..\n");
    }
    else
    {
        printf("Enter New Element to insert: ");
        scanf("%d", &n);
        newNode = (struct node *)malloc(sizeof(struct node));
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
        printf("List Not Found..\n");
    }
    else
    {
        temp = start;
        start = start->add;
        printf("Deleted node is %d\n", temp->data);
        free(temp);
    }
}

// Delete last node from linkelist
void delete_Last()
{
    if (start == NULL)
    {
        printf("List Not Found..\n");
    }
    else
    {
        temp = start;

        if (temp->add == NULL)
        {
            printf("Deleted Node %d\n", temp->data);
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
            printf("Deleted Node %d\n", temp->data);
            free(temp);
        }
    }
}

// Delete a node in the middle of the LinkedList
void delete_Middle()
{
    int pos, i = 1;

    if (start == NULL)
    {
        printf("List Not Found..\n");
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &pos);

        if (pos == 1)
        {
            temp = start;
            start = start->add;
            printf("Deleted node: %d\n", temp->data);
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
            printf("Position not found.\n");
        }
        else
        {
            next = temp->add;
            prev->add = next;
            printf("Deleted node: %d\n", temp->data);
            free(temp);
        }
    }
}

// Count the nodes in the LinkedList
void countNode()
{
    int count = 0;

    if (start == NULL)
    {
        printf("List Not Found..\n");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            count++;
            temp = temp->add;
        }
        printf("The Total Node is: %d\n", count);
    }
}

// Search for a node in the LinkedList
void searchNode()
{
    int s, f = 0;
    if (start == NULL)
    {
        printf("List Not Found..\n");
    }
    else
    {
        printf("Enter the data: ");
        scanf("%d", &s);

        temp = start;
        while (temp != NULL)
        {
            if (temp->data == s)
            {
                f = 1;
                break;
            }
            temp = temp->add;
        }

        if (f == 1)
        {
            printf("Search is Successful.\n");
        }
        else
        {
            printf("Search is not Successful.\n");
        }
    }
}
