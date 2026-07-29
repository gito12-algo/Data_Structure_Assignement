#include <stdio.h>
int linearSearch(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}
int main()
{
    int arr[100];
    int n, i, key, result;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    result = linearSearch(arr, n, key);
    if (result == -1)
    {
        printf("Element not found.\n");
    }
    else
    {
        printf("Element found at position %d.\n", result + 1);
        printf("Array index = %d\n", result);
    }
    return 0;
}
