/* Program to implement a double ended queue in C
 * 
 * Compilation : gcc -o dequeue 3_double_ended_queue.c
 * Execution : ./dequeue
 *
 * @Ujjwal, 1910991390, 29/08/2021
 * Assignment 6 (Linked List);
 */


#include <stdio.h>
#include<stdlib.h>
 
/*Definition of doubly Linked List*/

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*first=NULL;

/*Function to display List*/

void display(struct Node *first)
{
    while(first!=NULL)
    {
        printf("%d ",first->data);
        first=first->next;
    }
    printf("\n");
}

/*Function to insert element at head*/

void insertAtHead(struct Node *p, int value)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    struct Node *f=first;
    t->data=value;
    if(p==NULL)
    {
        first=t;
        first->prev=NULL;
        first->next=NULL;
    }
    else
    {
        f->prev=t;
        t->next=f;
        first=t;
        first->prev=NULL;
    }
}

/*Function to insert element at tail*/

void insertAtTail(struct Node *p, int value)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=value;
    if(p==NULL)
    {
        p=temp;
        p->prev=NULL;
        p->next=NULL;
    }
    else
    {
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
    temp->prev=p;
    temp->next=NULL;
    }
}

/*Function to peek topmost tail element on list*/

void peekTail(struct Node *p)
{
    if(p==NULL)
    {
        printf("EMPTY\n ");
        return;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        printf("%d\n",p->data);
    }
}

/*Function to peek topmost head element on list*/

void peekHead(struct Node *p)
{
    if(p)
    printf("%d\n",p->data);
    else
    {
        printf("EMPTY DEQUE !\n");
        return;
    }
}

/*Function to remove element from head*/


void removeFromHead(struct Node *p)
{
    struct Node *f;
    if(p==NULL)
    {
        printf("List is empty !! \n");
    }
    else
    {
        f=first;
        first=first->next;
        first->prev=NULL;
        free(f);
    }
}

/*Function to check if element is present in the list or not*/

void isPresent(struct Node *p, int value)
{
    while(p!=NULL)
    {
        if(value==p->data)
        {
            printf("Present\n");
            break;
        }
        else{
            printf("Not Present\n");
        }
        p=p->next;
    }
    
}

/*Function to remove element from tail*/

void removeFromTail(struct Node *p)
{
    struct Node *q;
    if(p==NULL)
    {
        printf("List is empty !! \n");
    }
    else
    {
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        q->next=NULL;
        free(p);
    }
}

int main()
{
    int choice,value;

while(1)
    {
    printf("1.Insert at head\n");
    printf("2.Insert at tail\n");
    printf("3.Remove from head\n");
    printf("4.Remove from tail\n");
    printf("5.Peek head\n");
    printf("6.Peek tail\n");
    printf("7.Check element is present?\n");
    printf("8.Exit\n");

    printf("Enter the choice : ");
    scanf("%d",&choice);

    
        switch(choice) {

            case 1: {
                printf("Enter element to insert at head : ");
                scanf("%d",&value);
                insertAtHead(first,value);
                display(first);
                break;
            }

            case 2: {
                printf("Enter element to insert at tail : ");
                scanf("%d",&value);
                insertAtTail(first,value);
                display(first);
                break;
            }

            case 3: {
                removeFromHead(first);
                display(first);
                break;
            }
            case 4: {
                removeFromTail(first);
                display(first);
                break;
            }
            case 5: {
                peekHead(first);
                break;
            }
            case 6: {
                peekTail(first);
                break;
            }
            case 7 : {
                printf("Enter element to check : ");
                scanf("%d",&value);
                isPresent(first,value);
                break;
            }
            case 8 : {
                exit(0);
            }
            default : {
                printf("Invalid Input\n");
            }
            
        }
    }
    return 0;
}
