#include <stdio.h>
#include <stdlib.h>

void create();
void createTail();
void insert_First();
void insert_Last();
void insertAtPos();
void delete_First();
void delete_Last();
void deleteAtPos();
void Display();
void countNode();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail = NULL;

int main()
{
    int choice;

    do
    {
        printf("\n================Linked List Menu================");
        printf("\n1. Create\n2. Insert_First \n3. Insert_Last \n4. Insert_Middle \n5. Delete_First \n6. Delete_Last \n7. Delete_Middle \n8. Display \n9. Exit \n10. Count Node");
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
            insertAtPos();
            break;
        case 5:
            delete_First();
            break;
        case 6:
            delete_Last();
            break;
        case 7:
            deleteAtPos();
            break;
        case 8:
            Display();
            break;
        case 9:
            printf("Exiting...");
            break;
        case 10:
            countNode();
            break;
        default:
            printf("Invalid choice! Please try again.");
        }
    } while (choice != 9);

    return 0;
}

void create()
{
    int choice = 1;

    while (choice)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->prev = newNode->next = NULL;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        printf("Do you want to continue (0/1): ");
        scanf("%d", &choice);
    }
}

void Display()
{
    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void insert_First()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = newNode->next = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insert_Last()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = newNode->next = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPos()
{
    int i = 1, pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("List not found\n");
    }
    else if (pos == 1)
    {
        insert_First();
    }
    else
    {
        struct node *temp = head;
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        while (i < pos - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

        if (newNode->next == NULL)
        {
            tail = newNode;
        }
    }
}

void delete_First()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        struct node *temp = head;
        if (head->next == NULL)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }
        free(temp);
    }
}

void delete_Last()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        struct node *temp = tail;
        if (head->next == NULL)
        {
            head = tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        free(temp);
    }
}

void deleteAtPos()
{
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else if (pos == 1)
    {
        delete_First();
    }
    else
    {
        struct node *temp = head;
        while (i < pos && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            printf("Position not found.\n");
        }
        else
        {
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            else
            {
                tail = temp->prev;
            }
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            free(temp);
        }
    }
}

void countNode()
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", count);
}
