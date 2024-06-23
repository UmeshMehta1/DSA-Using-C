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
};

struct node *head = NULL;

int main()
{
    int choice;

    do
    {
        printf("\n================Circular Linked List Menu================");
        printf("\n1. Create\n2. Insert_First \n3. Insert_Last \n4. Insert_Middle \n5. Delete_First \n6. Delete_Last \n7. Delete_Middle \n8. Display \n9. Exit \n10. Count Node");
        printf("\n========================================================");

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
    struct node *temp, *newNode;

    while (choice)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
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
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

void insert_First()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insert_Last()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
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
        temp->next = newNode;
    }
}

void delete_First()
{
    struct node *temp = head, *toDelete;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        toDelete = head;
        if (head->next == head)
        {
            head = NULL;
        }
        else
        {
            head = head->next;
            temp->next = head;
        }
        free(toDelete);
    }
}

void delete_Last()
{
    struct node *temp = head, *prevNode;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while (temp->next != head)
        {
            prevNode = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = NULL;
        }
        else
        {
            prevNode->next = head;
        }
        free(temp);
    }
}

void deleteAtPos()
{
    struct node *temp = head, *toDelete;
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
        while (i < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
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
