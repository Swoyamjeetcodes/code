#include <stdio.h>
int add(int* a[3][3], int* b[3][3])
{
    int i, j;
    int* c[3][3];
for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        *(c[i][j])=*(a[i][j])+*(b[i][j]);
    }
    printf("\n");
    return c;

}

int main()
{   int* a[3][3];
    int* b[3][3];
    int i, j;

    printf("\nenter the elements for the 1st matrix:");
        for(i=0;i<=2;i++)
            {
                for(j=0;j<=2;j++)
                scanf("%d",&a[i][j]);
            }
        printf("\nenter the elements for the 2nd matrix:");
        for(i=0;i<=2;i++)
            {
                for(j=0;j<=2;j++)
                scanf("%d",&b[i][j]);
            }
        add(a,b);
        for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
            printf("matrix after addition is:%p",*(c[i][j]));
            if(j==2)
            printf("\n");
    }
return 0;
}