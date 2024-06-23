#include <stdio.h>
#include <stdlib.h>

void create();
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

struct node *head = NULL;

int main()
{
    int choice;

    do
    {
        printf("\n================Doubly Circular Linked List Menu================");
        printf("\n1. Create\n2. Insert_First \n3. Insert_Last \n4. Insert_Middle \n5. Delete_First \n6. Delete_Last \n7. Delete_Middle \n8. Display \n9. Exit \n10. Count Node");
        printf("\n================================================================");

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
    struct node *newNode, *temp;

    while (choice)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = newNode->prev = NULL;

        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            temp = head->prev;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
        printf("Do you want to continue (0/1): ");
        scanf("%d", &choice);
    }
}

void Display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    else
    {
        temp = head;
        do
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

void insert_First()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        struct node *tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void insert_Last()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        struct node *tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

void insertAtPos()
{
    int pos, i = 1;
    struct node *newNode, *temp;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insert_First();
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        temp = head;
        while (i < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
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
        struct node *tail = head->prev;

        if (head->next == head)
        {
            head = NULL;
        }
        else
        {
            head = head->next;
            head->prev = tail;
            tail->next = head;
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
        struct node *temp = head->prev;

        if (head->next == head)
        {
            head = NULL;
        }
        else
        {
            temp->prev->next = head;
            head->prev = temp->prev;
        }
        free(temp);
    }
}

void deleteAtPos()
{
    int pos, i = 1;
    struct node *temp;
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
        temp = head;
        while (i < pos && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void countNode()
{
    struct node *temp = head;
    int count = 0;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        printf("Number of nodes: %d\n", count);
    }
}
