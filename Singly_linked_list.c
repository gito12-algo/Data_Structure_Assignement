#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insert()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;
}
void display()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
void search()
{
    int key;
    struct Node *temp = head;
    printf("Enter element to search: ");
    scanf("%d", &key);
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element Found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element Not Found\n");
}
void deleteNode()
{
    int key;
    struct Node *temp = head, *prev = NULL;
    printf("Enter element to delete: ");
    scanf("%d", &key);
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Element Not Found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void reverse()
{
    struct Node *prev = NULL, *curr = head, *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
int main()
{
    insert();
    insert();
    insert();
    printf("Linked List: ");
    display();
    search();
    deleteNode();
    printf("After Delete: ");
    display();
    reverse();
    printf("After Reverse: ");
    display();
    return 0;
}
