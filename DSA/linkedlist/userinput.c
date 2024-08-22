#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node *create(int n)
{
    struct node* head=NULL,*ptr;
    for(int i=0;i<n;i++)
    {
        struct node* p=(struct node*)malloc(sizeof(struct node));
        printf("Enter data[%d]:",i);
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            ptr->next=p;
        ptr=p;
    }
    return head;
}   
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{   
    struct node* head;
    int n;
    printf("\nEnter number of Nodes");
    scanf("%d",&n);
    head=create(n);
    
    traversal(head);
    
return 0;
}