#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev, *next;
};
struct Node *head = NULL;
void insert(int x)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = x;
    new->prev = NULL;
    new->next = head;

    if(head != NULL)
        head->prev = new;

    head = new;
}
void display()
{
    struct Node *temp = head;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void search(int x)
{
    struct Node *temp = head;
    while(temp)
    {
        if(temp->data == x)
        {
            printf("Found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Not Found\n");
}
void reverse()
{
    struct Node *temp = NULL, *curr = head;
    while(curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if(temp)
        head = temp->prev;
}
int main()
{
    insert(30);
    insert(20);
    insert(10);
    display();
    search(20);
    reverse();
    display();
    return 0;
}
