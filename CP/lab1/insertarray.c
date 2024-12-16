#include<stdio.h>
int main(){

int a[50]={1,2,3,4,5,6,7,8,9,10};
int i,pos,j;
printf("intial elements:");
for(i=0;i<10;i++){
    printf("%d",a[i]);
}
printf("\nnew element to be inserted: 5");
printf("\nposition:2\n");
//shift elements
for(i=10;i>=3;i--)
{
a[i]=a[i-1];
}
a[2]=5;
printf("new elements are:");
for(i=0;i<11;i++)
{
printf("%d",a[i]);
}
return 0;

}