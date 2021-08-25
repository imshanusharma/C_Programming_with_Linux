/* Program to implement queue operations using linked list
 * 
 * Compilation: gcc -o queue 2_queue_linked_list.c
 * Execution: ./queue
 *
 * @Ujjwal, 1910991390, 23/08/2021
 * Assignment 6 (Linked List)
 */

#include <stdio.h>
#include <stdlib.h>

/* Definition of Singly Linked List */

struct node {

    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
struct node *temp;
struct node *front1;

/* Function to enqueue element into Queue */

void enqueue(int val) {
	
    if(rear == NULL)
    {
	rear = (struct node *)malloc(sizeof(struct node));
	rear -> next = NULL;
	rear -> data = val;
	front = rear;
    }
    else
    {
	temp = (struct node *)malloc(sizeof(struct node));
	rear -> next = temp;
	temp -> data = val;
	temp -> next = NULL;
	rear = temp;
    }
    printf("********Element Enqueued**********\n\n");
}

/* Function to dequeue element from the Queue */

void dequeue() {

    front1 = front;

    if(front1 == NULL)
    {
	printf("**************Queue is empty*****************\n\n");
	return;
    }
    else
    {
	if(front1 -> next != NULL)
	{
	    front1 = front1 -> next;
	    printf("**************Element dequeued : %d ****************\n\n",front->data);
	    free(front);
	    front = front1;
	}
	else
	{
	    printf("**************Element Dequeued : %d ****************\n\n",front->data);
	    free(front);
	    front = NULL;
	    rear = NULL;
	}
    }

}


/*Function to peek first element of Queue*/

void peek() {

    if(front != NULL && rear != NULL)
    {
	printf("***************Peek : %d ****************\n\n",front->data);
	return;
    }
    printf("******************Queue is Empty********************");
}

/* Function to check if the queue is empty or not */

void is_empty() {

    if(front == NULL && rear == NULL)
    {
	printf("**************Queue Empty*************\n");
	return;
    }
    printf("*******************Not Empty*******************\n");
}

int main() {

    int choice;
    int val;
   
    while(1) {

    printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.is_empty\n5.Exit\n\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
    
        case 1 : 
	{
 	    printf("Enter the value to enqueue: ");
	    scanf("%d",&val);
	    enqueue(val);
	    break;
	}
	case 2 :
	{
	    dequeue();
	    break;
	}	
	case 3 :
	{
	    peek();
	    break;
	}
	case 4 :
	{
	    is_empty();
	    break;
	}
	case 5 :
	{
	    printf("Exiting...");
	    exit(0);
	}
	default :
	{
	    printf("Invalid Input\n");
	}
    }
    
    }

    return 0;
}
