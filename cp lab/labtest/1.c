// C program to separate even and odd nodes in a linkedlist
#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
	int data; 
	struct node *next; 
}; 

void segregateEvenOdd(struct node **head_ref) 
{ 
	struct node *end = *head_ref; 
	struct node *prev = NULL; 
	struct node *curr = *head_ref; 

	while (end->next != NULL) 
		end = end->next; 

	struct node *new_end = end; 
	while (curr->data %2 != 0 && curr != end) 
	{ 
		new_end->next = curr; 
		curr = curr->next; 
		new_end->next->next = NULL; 
		new_end = new_end->next; 
	} 
	if (curr->data%2 == 0) 
	{ 
		*head_ref = curr; 
		while (curr != end) 
		{ 
			if ( (curr->data)%2 == 0 ) 
			{ 
				prev = curr; 
				curr = curr->next; 
			} 
			else
			{ 
				prev->next = curr->next; 
				curr->next = NULL; 
				new_end->next = curr; 
				new_end = curr; 
				curr = prev->next; 
			} 
		} 
	} 

	else prev = curr; 

	if (new_end!=end && (end->data)%2 != 0) 
	{ 
		prev->next = end->next; 
		end->next = NULL; 
		new_end->next = end; 
	} 
	return; 
} 


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

void printList(struct node *node) 
{ 
	while (node!=NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 

int main()
{   
    struct node* head;
    int n;
    printf("\nEnter number of nodes");
    scanf("%d",&n);
    head=create(n);

    
	printf("\nOriginal Linked list \n"); 
	printList(head); 

	segregateEvenOdd(&head); 

	printf("\nModified Linked list \n"); 
	printList(head); 

	return 0; 
} 
