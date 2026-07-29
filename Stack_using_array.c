#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = value;
    printf("%d Pushed Successfully\n", value);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted Element = %d\n", stack[top]);
    top--;
}

void peek()
{
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Top Element = %d\n", stack[top]);
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements: ");

    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n----- STACK USING ARRAY -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}

