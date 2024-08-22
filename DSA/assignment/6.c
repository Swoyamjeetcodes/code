#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    printf("Enter the no. of rows: ");
    scanf("%d", &m);
    printf("Enter the no. of columns: ");
    scanf("%d", &n);
    int **arr = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        arr[i] = (int*)malloc(n * sizeof(int));
    }
    printf("Enter the elements: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int i;
    printf("Enter the value of i: ");
    scanf("%d", &i);
    check_sum(arr, m, n, i);

    return 0;
}

void check_sum(int **arr, int m, int n, int x)
{
    int sum_row = 0, sum_col = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == x)
            {
                sum_row += arr[i][j];
            }
            if (j == x)
            {
                sum_col += arr[i][j];
            }
        }
    }

    if (sum_row == sum_col)
    {
        printf("Sum of ith row = ith column \n");
    }
    else
    {
        printf("Sum of ith row is not = ith coulmn\n");
    }
}
