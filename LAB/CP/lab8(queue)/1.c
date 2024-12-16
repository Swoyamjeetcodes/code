//wap to implement queue using array

#include <stdio.h>
#define SIZE 5

int enQueue(int);
int deQueue();
int display();
int isfull();
int isempty();

int items[SIZE], front = -1, rear = -1;

int main() {
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if the queue is empty\n");
        printf("4. Check if the queue is full\n");
        printf("5. Display queue elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                enQueue(element);
                break;
            case 2:
                element = deQueue();
                if (element != -1) {
                    printf("Popped %d from the stack.\n", element);
                }
                break;
            case 3:
                if (isempty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("queue is not empty.\n");
                }
                break;
            case 4:
                if (isfull()) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
  return 0;
}
int isempty()
{
    if(rear==-1)
    printf("\nQueue is empty");
    else 
    printf("\nits not empty");
}
int isfull()
{
    if(rear==SIZE-1)
    printf("\nQueue is full");
    else
    printf("\nits not full");

}
int enQueue(int value) {
  if (rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nInserted -> %d", value);
  }
}

int deQueue() {
  if (front == -1)
    printf("\nQueue is Empty!!");
  else {
    printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

// Function to print the queue
int display() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}