/* Program to implement stack operations using linked list
 * 
 * Compilation: gcc -o stack 1_stack_linked_list.c
 * Execution: ./stack
 *
 * @Ujjwal, 1910991390, 21/08/2021
 * Assignment 6 (Linked List)
 */

#include <stdio.h>
#include <stdlib.h>

/* Definition of Singly Linked List */

struct node {

    int data;
    struct node *next;
};

struct node *head = NULL;

/* Function to push element into stack */

void push(int val) {
	
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    
    ptr->data = val;
    ptr->next = head;
    head = ptr;
    
    printf("**************\n");    
    printf("Element Pushed\n");
    printf("**************\n");    
}

/* Function to pop element from the stack */

void pop() {

    if(head == NULL)
    {
	printf("**************\n");
	printf("Stack is empty\n");
        printf("**************\n");    
	return;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
    printf("*************************\n");
    printf("Popped element is : %d\n",head->data);
    printf("*************************\n");

    temp = head;
    head = head->next;
    free(temp);
}

/*Function to peek topmost element of stack*/

void peek() {

    if(head == NULL)
    {
	printf("****************\n");
	printf("Stack is empty\n");
	printf("****************\n");
	return;
    }

    printf("***********\n");
    printf("Peek : %d\n",head->data);
    printf("***********\n");
}

/* Function to check if the stack is empty or not */

void is_empty() {

    if(head == NULL)
    {	
	printf("***************\n");
	printf("Stack is empty\n");
	printf("***************\n");
	return;
    }
    printf("**********\n");
    printf("Not Empty\n");
    printf("**********\n");
}

int main() {

    int choice;
    int val;
   
    while(1) {

    printf("1.Push\n2.Pop\n3.Peek\n4.is_empty\n5.Exit\n\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
    
        case 1 : 
	{
 	    printf("Enter the value to push: ");
	    scanf("%d",&val);
	    push(val);
	    break;
	}
	case 2 :
	{
	    pop();
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
