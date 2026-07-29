#include <stdio.h>
int gcdRec(int a, int b)
{
    if(b == 0)
        return a;
    return gcdRec(b, a % b);
}
int gcdIter(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    printf("GCD (Recursion) = %d\n", gcdRec(a, b));
    printf("GCD (Iteration) = %d\n", gcdIter(a, b));
    return 0;
}
