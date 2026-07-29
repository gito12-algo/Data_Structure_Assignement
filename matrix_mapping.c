#include <stdio.h>
int diagonalIndex(int i, int j)
{
    if(i == j)
        return i;
    return -1;
}
int lowerIndex(int i, int j)
{
    if(i >= j)
        return (i * (i + 1)) / 2 + j;
    return -1;
}
int upperIndex(int i, int j, int n)
{
    if(i <= j)
        return (n * i - (i * (i - 1)) / 2 + j - i);
    return -1;
}
int symmetricIndex(int i, int j)
{
    if(i < j)
    {
        int temp = i;
        i = j;
        j = temp;
    }
    return (i * (i + 1)) / 2 + j;
}
int main()
{
    int i, j, n;
    printf("Enter row index (i): ");
    scanf("%d", &i);
    printf("Enter column index (j): ");
    scanf("%d", &j);
    printf("Enter order of matrix (n): ");
    scanf("%d", &n);
    printf("\nDiagonal Index = %d\n", diagonalIndex(i, j));
    printf("Lower Triangular Index = %d\n", lowerIndex(i, j));
    printf("Upper Triangular Index = %d\n", upperIndex(i, j, n));
    printf("Symmetric Matrix Index = %d\n", symmetricIndex(i, j));
    return 0;
}
