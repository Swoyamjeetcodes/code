//double link lst traversal

#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;

};
//traversal
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
//insert at index
struct node *insertatindex(struct node *head,int data,int index)
{
    struct node *p=head;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }   
        ptr->next=p->next;
        p->next=ptr;
        ptr->prev=p;
        ptr->data=data;

    return head;
}

int main()
{ 
    struct node *head;
    int data,index,n;

    printf("\nno of nodes:");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        node[i]= (struct node *)malloc(sizeof(struct node));
    }
    
    printf("\nLinked List:");
    traversal(head);
    printf("\n");
    //user input
    printf("\nData to be inserted:");
    scanf("%d",&data);
    printf("\nEnter at which position to be inserted:");
    scanf("%d",&index);

    head=insertatindex(head,data,index);
    printf("\nAfter insertion:");
    traversal(head);
return 0;
}