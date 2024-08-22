/*WAP to represent a given sparse matrix in 3-tuple format using 2-D array. 

Sample Input:

Enter size of the sparse matrix: 4 5
Enter elements of sparse matrix: 0  0  33  0  0  0  17  0  0  0  0  0  0  46  0  0  0  0  0  51

Sample Output:
sparse matrix in 3-tuple format
4   5   4
0   2   33
1   1   17
2   3   46
3   4   51*/

// C++ program for Sparse Matrix Representation
// using Array
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

	int size = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			if (sparseMatrix[i][j] != 0)
				size++;

	int compactMatrix[size][3];

	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			if (sparseMatrix[i][j] != 0)
			{
				compactMatrix[0][k] = i;
				compactMatrix[1][k] = j;
				compactMatrix[2][k] = sparseMatrix[i][j];
				k++;
			}

    printf("R C   Element\n");
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<size; j++)
			printf("%d ", compactMatrix[i][j]);

		printf("\n");
	}
	return 0;
}
