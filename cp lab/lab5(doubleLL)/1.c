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
        ptr->data=data;
        ptr->next=p->next;
        ptr->prev=p;
        p->next->prev=ptr;
        p->next=ptr;

    return head;
}

int main()
{ 
    struct node *head;
    struct node *one;
    struct node *two;
    struct node *three;
    int data,index;

    head = (struct node *)malloc(sizeof(struct node));
    one = (struct node *)malloc(sizeof(struct node));
    two = (struct node *)malloc(sizeof(struct node));
    three = (struct node *)malloc(sizeof(struct node));

    //data to nodes
    head = one;
    one->data = 10;
    two->data = 11;
    three->data = 12;

    //connecting nodes
    one->prev=head;
    one->next = two;
    two->prev=one;
    two->next = three;
    three->prev=two;
    three->next = NULL;
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