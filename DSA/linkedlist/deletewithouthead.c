#include <stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};

void deletewh(struct node *pos)
{
    pos->data=pos->next->data;
    pos->next=pos->next->next;

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
    traversal(head);
    deletewh(two);
    printf("\n");
    traversal(head);

return 0;
}