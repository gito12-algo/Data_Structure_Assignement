#include <stdio.h>
void toSparse(int mat[3][3], int r, int c)
{
    int i, j;
    printf("Row Col Value\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(mat[i][j] != 0)
            {
                printf("%d   %d   %d\n", i, j, mat[i][j]);
            }
        }
    }
}
int main()
{
    int mat[3][3] =
    {
        {1, 0, 0},
        {0, 2, 0},
        {3, 0, 4}
    };
    toSparse(mat, 3, 3);
    return 0;
}
