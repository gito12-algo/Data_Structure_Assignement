#include <stdio.h>
int fibRec(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibRec(n - 1) + fibRec(n - 2);
}
void fibIter(int n)
{
    int a = 0, b = 1, c, i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
}
int main()
{
    int n, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci (Recursion): ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", fibRec(i));
    }
    printf("\n");
    printf("Fibonacci (Iteration): ");
    fibIter(n);
    return 0;
}
