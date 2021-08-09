/* Program to check whether the sequence of brackets in the given string is balanced or not
 *
 * Compilation : gcc -o bp 1_balanced_parentheses.c
 * Execution ./bp
 *
 * @UJJWAL, 1910991390, 07/08/2021
 * Assignment 4 (Stacks and Queues)
 */

#include <stdio.h>
#define SIZE 20

char stack[SIZE];
int top = 0;

/*Function to push element in stack*/

void push(char val)
{
    if(top == SIZE)
    {
	printf("Stack Overflow");
    }
    else
    {
	stack[top++] = val;
    }
}

/*Function to remove and return topmost element in the stack*/

char pop() {

    char value;
    if(top == 0)
    {
	printf("Stack undeflow");
    }
    value = stack[top-1];
    top = top-1;
    return value;
}

/*Function to only return topmost element of stack*/

char peek() {

    if(top == 0)
    {
	printf("Stack is empty");
    }
    return stack[top-1];
}

/*Function to check whether stack is empty or not*/

int is_empty()
{
    if(top == 0)
	    return 1;
    return 0;
}

int main() {

    char str[80];

    printf("Enter the string : ");
    scanf("%s",str);

    for(int i = 0; str[i] != '\0'; i++)
    {
	switch(str[i])
	{
	    case '(' :
	    {
		push('(');
		break;
	    }
	    case '[' :
	    {
	        push('[');
		break;
	    }
	    case '{' :
	    {
		push('{');
		break;
	    }
	    case ')' :
	    {
		if(peek() != '(')
		{
		    break;
		}
		else
	       	{
		    pop();
		}
		break;
	    }
	    case '}' :
	    {
		if(peek() != '{')
		{
		    
		    break;
		}
		else 
		{
		    pop();
		}
		break;
	    }
	    case ']' :
	    {
		if(peek() != '[')
		{
		    break;
		}
		else
		{
		    pop();
		}
		break;
	    }
	}
    }

    if(is_empty() == 1)
    {
	    printf("True");
    }
    else {
	   printf("False");
    }
    return 0;
}
