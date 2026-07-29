#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff, exp;
    struct Node *next;
};
void insert(struct Node **head, int c, int e)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = *head;
    *head = newNode;
}
void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);

        if(head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}
void add(struct Node *p1, struct Node *p2)
{
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->exp == p2->exp)
        {
            printf("%dx^%d", p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->exp > p2->exp)
        {
            printf("%dx^%d", p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else
        {
            printf("%dx^%d", p2->coeff, p2->exp);
            p2 = p2->next;
        }
        if(p1 != NULL || p2 != NULL)
            printf(" + ");
    }
    while(p1 != NULL)
    {
        printf("%dx^%d", p1->coeff, p1->exp);
        p1 = p1->next;
        if(p1 != NULL)
            printf(" + ");
    }
    while(p2 != NULL)
    {
        printf("%dx^%d", p2->coeff, p2->exp);
        p2 = p2->next;
        if(p2 != NULL)
            printf(" + ");
    }
    printf("\n");
}
int main()
{
    struct Node *p1 = NULL, *p2 = NULL;
    insert(&p1, 1, 0);
    insert(&p1, 2, 1);
    insert(&p1, 3, 2);
    insert(&p2, 4, 0);
    insert(&p2, 5, 2);
    printf("Polynomial 1 = ");
    display(p1);
    printf("Polynomial 2 = ");
    display(p2);
    printf("Result = ");
    add(p1, p2);
    return 0;
}
