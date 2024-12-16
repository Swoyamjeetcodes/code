#include <stdio.h>

int max(int a,int b){ return (a>b) ? a:b; }

int knapsack(int m,int wt[], int p[],int n)
    {
        //n = no of objects
        //m = bag size
        int i,w;
        int ks[n+1][m+1];
        for(i=0;i<=n;i++)
            {
                for(w=0;w<=m;w++)
                    {
                        if(i==0||w==0)
                            ks[i][w]=0;
                        else if(wt[i]<=w)
                            ks[i][w]=max(ks[i-1][w],ks[i-1][w-wt[i-1]]+p[i-1]);
                        else
                            ks[i][w]=ks[i-1][w];
                    }
            }
        return ks[n][m];
    }
    int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);
    
    int wt[n], p[n];

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the profits of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int max_value = knapsack(capacity, wt, p, n);
    printf("Maximum value in Knapsack = %d\n", max_value);

    return 0;
}

