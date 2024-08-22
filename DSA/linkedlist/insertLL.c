#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
// insert at head
struct node *inserth(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

//insert at index
struct node *insertatindex(struct node *head,int data,int index)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }   
        ptr->next=p->next;
        p->next=ptr;
        ptr->data=data;

    return head;
}

//insert at end

struct node *insertatend(struct node *head,int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;

    return head;
}
//delete at head 
struct node* deletehead();
//traversal
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
    struct node *head;
    struct node *one;
    struct node *two;
    struct node *three;

    head = (struct node *)malloc(sizeof(struct node));
    one = (struct node *)malloc(sizeof(struct node));
    two = (struct node *)malloc(sizeof(struct node));
    three = (struct node *)malloc(sizeof(struct node));

    //data to nodes
    head = one;
    one->data = 10;
    two->data = 11;
    three->data = 13;
    three->data = three->data + two->data;


    //connecting nodes
    one->next = two;
    two->next = three;
    three->next = NULL;
    traversal(head);
    //insert at head calling 
    head = inserth(head,47);
    printf("\nAfter insertion at head :\n");
    traversal(head);

    //insert at index calling
    printf("\ninsertion at index\n");
    head=insertatindex(head,69,2);
    traversal(head);
    
    //insert at end calling
    printf("\nInsertion at end\n");
    head = insertatend(head, 56);
    traversal(head);

    return 0;
}