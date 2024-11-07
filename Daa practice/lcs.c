#include <stdio.h>
#include <string.h>
#define MAX 100

int max(int a,int b){ return (a>b) ? a:b; }

int LCS(int n,int m,char x[], char y[])
    {   
        int i,j;
        int lcs[n+1][m+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0||j==0)
                
                    lcs[i][j]=0;
                else if(x[i-1]==y[j-1])
                    lcs[i][j]=1+lcs[i-1][j-1];
                else
                    lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
            }
        }
    return lcs[n][m];
    }
int main() {
    char X[MAX], Y[MAX];
    
    printf("Enter first string: ");
    fgets(X, MAX, stdin);
    printf("Enter second string: ");
    fgets(Y, MAX, stdin);

    // Remove newline character added by fgets if present
    X[strcspn(X, "\n")] = '\0';
    Y[strcspn(Y, "\n")] = '\0';

    int a = strlen(X);
    int b = strlen(Y);
    int q = LCS(a, b, X, Y);

    printf("Longest Common Subsequence length: %d\n", q);
    return 0;
}
