// wap to create an array of 10 elements and display all the lements present in  array
#include <stdio.h>
int main()
{

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    for (i = 9; i >= 0; --i)
    {
        printf("%d", a[i]);
    }
    return 0;
}