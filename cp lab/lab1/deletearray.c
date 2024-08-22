#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, n, pos, arr[10];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the index of the element to be deleted: ");
    scanf("%d", &pos);
    for (i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("The array after deleting the element is: ");
    for (i = 0; i < n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}