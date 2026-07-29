#include <stdio.h>
int factRec(int n)
{
    if(n == 0 || n == 1)
        return 1;
    return n * factRec(n - 1);
}
int factIter(int n)
{
    int i, fact = 1;
    for(i = 1; i <= n; i++)
        fact *= i;
    return fact;
}
void factorsRec(int n, int i)
{
    if(i > n)
        return;
    if(n % i == 0)
        printf("%d ", i);
    factorsRec(n, i + 1);
}
void factorsIter(int n)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(n % i == 0)
            printf("%d ", i);
    }
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial (Recursion) = %d\n", factRec(n));
    printf("Factorial (Iteration) = %d\n", factIter(n));
    printf("Factors (Recursion) = ");
    factorsRec(n, 1);
    printf("\nFactors (Iteration) = ");
    factorsIter(n);
    return 0;
}
