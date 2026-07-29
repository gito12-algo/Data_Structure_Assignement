#include <stdio.h>
#define MAX 5
int stack[MAX], top = -1;
void push(int x)
{
    stack[++top] = x;
}
void reverse()
{
    int i, temp;
    for(i = 0; i <= top / 2; i++)
    {
        temp = stack[i];
        stack[i] = stack[top - i];
        stack[top - i] = temp;
    }
}
void display()
{
    int i;
    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}
int main()
{
    push(10);
    push(20);
    push(30);
    printf("Before Reverse: ");
    display();
    reverse();
    printf("After Reverse: ");
    display();
    return 0;
}
