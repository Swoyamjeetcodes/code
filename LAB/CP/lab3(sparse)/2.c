/*WAP to perform transpose of a given sparse matrix in 3-tuple format.

Sample Input:
Enter sparse matrix in 3-tuple format
4   5   4
0   2   33
1   1   17
2   3   46
3   4   51

Sample Output:

Transpose of sparse matrix:
R   C  Element
5   4   4
1   1   17
2   0   33
3   2   46
4   3   51*/
#include<stdio.h>

int main()
{
	int sparseMatrix[4][5] =
	{
		{0 , 0 , 33 , 0 , 0 },
		{0 , 17 , 0 , 0 , 0 },
		{0 , 0 , 0 , 46 , 0 },
		{0 , 0 , 0 , 0 , 51 }
	};
    int i,j;
    int transpose[5][4];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
        transpose[i][j]=sparseMatrix[j][i];
        printf("%d ",transpose[i][j]);
        }
        printf("\n");
    }

	int size = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			if (transpose[i][j] != 0)
				size++;

	int compactMatrix[3][size];

	int k = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			if (transpose[i][j] != 0)
			{
				compactMatrix[0][k] = i;
				compactMatrix[1][k] = j;
				compactMatrix[2][k] = transpose[i][j];
				k++;
			}

    printf("\nR C   Element\n");
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<3; j++)
			printf("%d ", compactMatrix[j][i]);

		printf("\n");
	}
	return 0;
}

