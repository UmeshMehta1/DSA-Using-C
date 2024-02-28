/*checks whether the parentheses in a given mathematical expression are balanced, utilizing a stack for push and pop operations to validate the correct pairing of opening and closing parentheses.*/

#include <stdio.h>

#define MAX_SIZE 50

#define TRUE 1
#define FALSE 0

// stack structure creation
struct Stack
{
    char arr[MAX_SIZE];
    int top;
};



// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1 ? TRUE : FALSE;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1 ? TRUE : FALSE;
}

// Function to push a character onto the stack
void push(struct Stack *stack, char data)
{
    if (isFull(stack))
    {
        printf("Stack Overflow: Cannot push %c, stack is full\n", data);
    }
    else
    {
        stack->arr[++stack->top] = data;
        printf("Pushed %c onto the stack\n", data);
    }
}

// Function to pop a character from the stack
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow: Cannot pop, stack is empty\n");
        return '\0';
    }
    else
    {
        printf("Popped %c from the stack\n", stack->arr[stack->top]);
        return stack->arr[stack->top--];
    }
}

// Function to check if parentheses are matching
int areMatching(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
                   (opening == '{' && closing == '}') ||
                   (opening == '[' && closing == ']')
               ? TRUE
               : FALSE;
}

// Function to check if parentheses are balanced
int areParenthesesBalanced(const char *expression)
{
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; ++i)
    {
        char currentChar = expression[i];

        if (currentChar == '(' || currentChar == '{' || currentChar == '[')
        {
            push(&stack, currentChar);
        }
        else if (currentChar == ')' || currentChar == '}' || currentChar == ']')
        {
            if (isEmpty(&stack) || !areMatching(pop(&stack), currentChar))
            {
                return FALSE;
            }
        }
    }

    return isEmpty(&stack) ? TRUE : FALSE;
}

int main()
{
    char expression[MAX_SIZE];

    printf("Enter a mathematical expression: ");
    fgets(expression, MAX_SIZE, stdin);

    if (areParenthesesBalanced(expression))
    {
        printf("Parentheses are balanced\n");
    }
    else
    {
        printf("Parentheses are not balanced\n");
    }

    return 0;
}