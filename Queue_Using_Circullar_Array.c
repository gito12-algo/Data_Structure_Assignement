#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int x)
{
    if((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
}
void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted Element = %d\n", queue[front]);
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}
void display()
{
    int i;
    if(front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    i = front;
    while(1)
    {
        printf("%d ", queue[i]);

        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Queue before Dequeue:\n");
    display();
    dequeue();
    printf("Queue after Dequeue:\n");
    display();
    return 0;
}
