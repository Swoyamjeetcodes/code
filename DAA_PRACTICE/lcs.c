#include <stdio.h>
#include <string.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void LCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int L[MAX][MAX]; // Table to store lengths of longest common subsequence

    // Building the L table in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0; // Base case
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1; // Characters match
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); // Characters don't match
            }
        }
    }

    // Length of LCS is in L[m][n]
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; // Null-terminate the string

    // Start from the bottom right corner of the L table
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1]; // If they match, it's part of LCS
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--; // Move up
        } else {
            j--; // Move left
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[MAX], Y[MAX];
    
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);
    
    LCS(X, Y);

    return 0;
}