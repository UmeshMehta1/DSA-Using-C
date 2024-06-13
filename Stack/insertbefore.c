#include <stdio.h>
#include <stdlib.h>

struct product {
    int id;
    char name[50];
    float price;
};

struct node {
    struct product data;
    struct node *next;
    struct node *prev;
};

struct node *header = NULL;

struct node *getnode(int n) {
    struct node *ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL) {
        printf("Memory Allocation failed..");
        exit(0);
    }
    ptrnew->data.id = n;
    ptrnew->next = NULL;
    ptrnew->prev = NULL;
    return ptrnew;
}

void insertFirst(struct node *ptrnew) {
    if (header != NULL) {
        header->prev = ptrnew;
    }
    ptrnew->next = header;
    ptrnew->prev = NULL;
    header = ptrnew;
}

void insertLast(struct node *ptrnew) {
    struct node *ptrthis = header;
    if (header == NULL) {
        header = ptrnew;
    } else {
        while (ptrthis->next != NULL) {
            ptrthis = ptrthis->next;
        }
        ptrthis->next = ptrnew;
        ptrnew->prev = ptrthis;
    }
}

void insertAfter(struct node *ptrprev, struct node *ptrnew) {
    if (ptrprev == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    ptrnew->next = ptrprev->next;
    if (ptrprev->next != NULL) {
        ptrprev->next->prev = ptrnew;
    }
    ptrnew->prev = ptrprev;
    ptrprev->next = ptrnew;
}

void insertBefore(struct node *ptrnext, struct node *ptrnew) {
    if (ptrnext == header) {
        ptrnew->next = header;
        header->prev = ptrnew;
        header = ptrnew;
    } else {
        ptrnew->next = ptrnext;
        ptrnew->prev = ptrnext->prev;
        ptrnext->prev->next = ptrnew;
        ptrnext->prev = ptrnew;
    }
}

void display() {
    struct node *ptrthis = header;
    if (header == NULL) {
        printf("List is Empty..\n");
    } else {
        printf("List Contains:\n");
        while (ptrthis != NULL) {
            printf("%d ", ptrthis->data.id);
            ptrthis = ptrthis->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int i;
    printf(".............DOUBLY LINKED LIST....................\n");
    for (i = 0; i < 10; i++) {
        insertFirst(getnode(i + 1));
    }
    display();

    do {
        printf("Enter your choice\n");
        printf("1. Insert First\n2. Insert At last\n3. Insert After\n4. Insert Before\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter the value to insert at the beginning: ");
                int val1;
                scanf("%d", &val1);
                insertFirst(getnode(val1));
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                int val2;
                scanf("%d", &val2);
                insertLast(getnode(val2));
                break;
            case 3:
                printf("Enter the value to insert after: ");
                int afterVal;
                scanf("%d", &afterVal);
                printf("Enter the value to insert: ");
                int newVal;
                scanf("%d", &newVal);
                struct node *ptrprev = header;
                while (ptrprev != NULL && ptrprev->data.id != afterVal) {
                    ptrprev = ptrprev->next;
                }
                if (ptrprev == NULL) {
                    printf("Node with value %d not found.\n", afterVal);
                } else {
                    insertAfter(ptrprev, getnode(newVal));
                }
                break;
            case 4:
                printf("Enter the value to insert before: ");
                int beforeVal;
                scanf("%d", &beforeVal);
                printf("Enter the value to insert: ");
                int newValBefore;
                scanf("%d", &newValBefore);
                struct node *ptrnext = header;
                while (ptrnext != NULL && ptrnext->data.id != beforeVal) {
                    ptrnext = ptrnext->next;
                }
                if (ptrnext == NULL) {
                    printf("Node with value %d not found.\n", beforeVal);
                } else {
                    insertBefore(ptrnext, getnode(newValBefore));
                }
                break;
            case 5: 
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (choice != 6); 

    return 0;
}