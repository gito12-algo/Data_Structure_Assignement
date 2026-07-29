#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *front = NULL, *rear = NULL;

void insertFront(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }

    printf("%d inserted at Front\n", x);
}

void insertRear(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }

    printf("%d inserted at Rear\n", x);
}

void deleteFront()
{
    if (front == NULL)
    {
        printf("Deque is Empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted = %d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
}

void deleteRear()
{
    if (rear == NULL)
    {
        printf("Deque is Empty\n");
        return;
    }

    struct Node *temp = rear;
    printf("Deleted = %d\n", rear->data);

    rear = rear->prev;

    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    free(temp);
}

void display()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque: ");

    temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n----- DEQUE USING LINKED LIST -----\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(value);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;

        case 5:
            display();
            break;

        case 6:
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
