/* Program to convert infix arithmetical notation to postfix notation
 *
 * Compilation: gcc -o itop infix_to_postfix.c
 * Execution: ./itop
 *
 * @Ujjwal, 1910991390, 09/08/2021
 * Assignment 4 (Stacks and queues)
 */

#include <stdio.h>
#include <ctype.h>

#define MAX 20

char stack[MAX];
int queue[MAX];
int tail = 0;
int top = 0;
int head = 0;

void push_queue(int val) {

    if(tail == MAX)
    {
	printf("Queue is full");
    }
    else
    {
	queue[tail++] = val;
    }
}

void push_stack(char val) {

    if(top == MAX)
    {
	printf("Stack Overflow");
    }
    else
    {
	stack[top++] = val;
    }
}

int pop_stack() {

    int element;
    if(top == 0)
    {
	printf("Stack Underflow");
    }
    else
    {
	element = stack[top-1];
	top = top - 1;
	return element;
    }
}

int pop_queue() {

    int element;
    int i = 0;
    if(tail == head)
    {
	printf("Queue is empty");
    }
    else
    {
	element = queue[head];
	while(i < tail)
	{
	    queue[head + i] = queue[head + i + 1];
	    i++;
	}
	tail--;
	return element;
    }
}

int main() {

    char str[80];

    printf("Enter the infix notation string: ");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
	if(isdigit(str[i]))
	{
	    push_queue(str[i] - '0');
	}
	else if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
	{
	    push_stack(str[i]);
	}
	else if(str[i] == ')')
	{
	    while(tail > head)
	    {
		printf("%d",pop_queue());
	    }
	    printf("%c",pop_stack());
	}
	
    }
    return 0;
}
