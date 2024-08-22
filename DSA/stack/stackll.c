#include <stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};

struct node* top=NULL;

void push(int x)
{   
    
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
    
}
void pop()
{
    struct node* temp;
    temp=top;
    top=top->next;
    free(temp);
}
void traversal()
{   
    struct node* ptr;
    ptr=top;
    while(ptr !=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    pop();
    traversal();
return 0;
}