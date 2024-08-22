#include<stdio.h>
int stack[100];
int top=-1;
void pop()
{
    if(top==-1)
    {
        printf("stack empty");
    }
    else
    {
        --top;
    }
}
int push(int x)
{
    if(top==99)
    {
        printf("stack is full");
    }      
    else
    {
        top++;
        stack[top]=x;
    }
    return top;
}
void isempty()
{
    if(top==-1)
    {
        printf("\nstack is empty");
    }
    else
    {
        printf("\nstack is not empty");
    }
}
void isfull()
{
    if(top==99)
    {
        printf("\nstack is full");
    }
    else
    {
        printf("\nstack is not full");
    }
}
void travsersal()
{
    for(int i=0;i<=top;i++)
    {
        printf("%d",stack[i]);
    }
}   
int main()
{   
    push(4);
    push(3);
    pop();
    travsersal();
    isempty();
    isfull();
}