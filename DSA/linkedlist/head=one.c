#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head;
    struct node *one;
    struct node *two;
    struct node *three;
    struct node *five;

    head = (struct node *)malloc(sizeof(struct node));
    one = (struct node *)malloc(sizeof(struct node));
    two = (struct node *)malloc(sizeof(struct node));
    three = (struct node *)malloc(sizeof(struct node));
    
    head->data=1000;
    head->next=three;
    
    one->data = 10;
    one->next = two;

    two->data = 11;
    two->next=three;
    
    three->data = 13;
    three->next=NULL;

    printf("%d",one->next->data);
    printf("%d",head->next->data);

    head=one;
    
    printf("%d",head->next->data);
    printf("%d",one->next->data);

    printf("%d",five);
 
    return 0;
}