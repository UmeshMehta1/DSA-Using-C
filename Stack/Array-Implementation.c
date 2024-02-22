#include <stdio.h>
#include <conio.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
struct stack
{
    int tos;        // top of the stack
    int items[MAX]; // array is used as storehouse of stack
};

int isEmplty(struct stack *s) // underflow test
{
    // return s-> tos =-1;
    if (s->tos == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
int isFull(struct stack *s) // overflow test
{
    // return s->tos==MAX-1;
    if (s->tos == MAX - 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int push(struct stack *s, int num)
{
    if (isFull(s)) // if stack if full then dont push
    {
        return FALSE; // return fa;se tp indicate that push has failed.
    }
    else
    {
        s->tos++;
        s->items[s->tos] = num;
        return TRUE; // return ture indicating the sucess of push
    }
}

int pop(struct stack *s)
{
    // if (isEmplty(s)) // stack underlow
    // {
    //     return TRUE; // pop failed
    // }
    // else
    // {
    //     s->tos--;
    //     return TRUE; // pop sucess
    // }

    // int num = s->items[s->tos];
    // s->tos--;
    // return num; //

    return s->items[s->tos--];
}

int peek(struct stack *s)
{
    return s->items[s->tos];
}

void display(struct stack *s)
{
    int i;
    if (isEmplty(s))
    {
        printf("\nStack is Empty.");
    }
    else
    {
        printf("\nStack contains:\n");
        for (i = s->tos; i >0; i--)
        {
            printf("\n%d",s->items[i]);
        }
    }
}

void main()
{
    struct stack s;
    char choice;
    int num;
    s.tos = -1; // empty stack initialized
    do
    {
        printf("\nSelect an option :\n1.push\n2.pop\n3.display\n4.Exit\n");
        printf("\nChoose The option: ");
        fflush(stdin);
        choice = getche();
        switch (choice)
        {
        case '1':
            printf("\nEnter a number: ");
            scanf("%d", &num);
            if (push(&s, num))
            {
                printf("\nItem pushed into the stack sucessfully");
            }
            else
            {
                printf("\nStack overflow. Pop some items before push.");
            }
            break;
        case '2':

            if (isEmplty(&s))
            {
                printf("\nStack overflow. Pop some items before push.");
            }
            else
            {
                num = peek(&s);
                pop(&s);
                printf("\n%d was poped from the stack", pop(&s));
            }
            break;
        case '3':
            display(&s);
            break;
        case '4':
            printf("\nSorry to see you go. ");

            break;
        default:
            break;
        }
    } while (TRUE);
}