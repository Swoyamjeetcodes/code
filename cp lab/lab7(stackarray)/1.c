#include <stdio.h>
#include<stdlib.h>
#define maxsize 100
int stack[maxsize];
int top=-1;

void push(int x)
{
    if(top==maxsize-1)
    {printf("stack is full");}
    else
    {
        top=top+1;
        stack[top]=x;
    }
}
int main()
{
int x;
printf("\nEnter data to be inserted:");
scanf("%d",&x);
printf()
push(x);
//print stack
for(int i=0;i<=top;i++)
{
    printf("%d",stack[i]);
}
return 0;
}