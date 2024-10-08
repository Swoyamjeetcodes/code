#include<stdio.h>
#include<malloc.h>
int* getpoly(int);
void showpoly(int *,int);
int* addpoly(int *,int,int *,int);
int* mulpoly(int *,int,int *,int);
int main(void)
{
 int *p1,*p2,*p3,d1,d2,d3;
 /*get poly*/
 printf("\nEnter the degree of the 1st polynomial:");
 scanf("%d",&d1);
 p1=getpoly(d1);
 printf("\nEnter the degree of the 2nd polynomial:");
 scanf("%d",&d2);
 p2=getpoly(d2);
 printf("Polynomials entered are\n\n");
 showpoly(p1,d1);
 printf("and\n\n");
 showpoly(p2,d2);
 /*compute the sum*/
 d3=(d1>=d2?d1:d2);
 p3=addpoly(p1,d1,p2,d2);
 printf("Sum of the polynomials is:\n");
 showpoly(p3,d3);
 /*compute product*/
 p3=mulpoly(p1,d1,p2,d2);
 printf("Product of the polynomials is:\n");
 showpoly(p3,d1+d2);
}
int* getpoly(int degree)
{
 int i,*p;
 p=malloc((1+degree)*sizeof(int));
 for(i=0;i<=degree;i++)
 {
  printf("\nEnter coefficient of x^%d:",i);
  scanf("%d",(p+i));
 }
 return(p);
}
void showpoly(int *p,int degree)
{
 int i;
 for(i=0;i<=degree;i++)
  printf("%dx^%d + ",*(p+i),i);
 printf("\b\b\b   ");
 printf("\n");
}
int* addpoly(int *p1,int d1,int *p2,int d2)
{
 int i,degree,*p;
 degree=(d1>=d2?d1:d2);
 p=malloc((1+degree)*sizeof(int));
 for (i=0;i<=degree;i++)
  if((i>d1) && (i<=d2))
   *(p+i)=*(p2+i);
  else if((i>d2) && (i<=d1))
   *(p+i)=*(p1+i);
  else
      *(p+i)=*(p1+i)+*(p2+i);
 return(p);
}

int* mulpoly(int *p1,int d1,int*p2,int d2)/* this is the function of concern*/
{
 int i,j,*p;
 p=malloc((1+d1+d2)*sizeof(int));
 for(i=0;i<=d1;i++)
  for(j=0;j<=d2;j++)
   p[i+j]+=p1[i]*p2[j];
 return(p);
}