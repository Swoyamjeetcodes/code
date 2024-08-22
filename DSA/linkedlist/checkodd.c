#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
    void checkodd(struct node* ptr)
    {   
        int ctr=0;
        while (ptr != NULL)
        {   
        if(ptr->data%2==1)
        {
            ctr++;
        }
        ptr = ptr->next;
        }
    
        printf("\nThe no of odd numbers in the linked list is %d",ctr);
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
    one->data = 13;
    two->data = 11;
    three->data = 15;

    //connecting nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    checkodd(head);


return 0;
}