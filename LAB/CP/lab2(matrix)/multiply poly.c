#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a1,*a2;
        a1=(int*) malloc(10*sizeof(int));
        a2=(int*) malloc(10*sizeof(int));
    int m,n;
    int i,j;

        printf("\nEnter size of first array");
        scanf("%d",&m);
        printf("\nEnter size of second array");
        scanf("%d",&n);
        printf("\nenter the elements for the 1st array:");
        for(i=0;i<m;i++)
            {
                scanf("%d",&a1[i]);
            }
        printf("\nenter the elements for the 2nd array:");
        for(i=0;i<n;i++)
            {
                scanf("%d",&a2[i]);
            }
            for(i=0;i<m;i++)
            {
                printf(" %d",a1[i]);
            }
            int *prod;
           prod = (int*)malloc(m+n-1 * sizeof(int));
            for (int i = 0; i <m+n-1; i++)
                {
                prod[i] = 0;
                }

                    for(i=0;i<m;i++)
                    {
                        for(j=0;j<n;j++)
                        {
                             prod[i+j] = prod[i+j] + a1[i] * a2[j];
                        }
                    }
            for(i=0;i<m+n-1;i++)
            {
                printf("\n%d ",prod[i]);
            }
                    
            free(a1);
            free(a2);
            free (prod);
            return 0;
}