/* Program to find the maximum area in histogram
 *
 * Compilation: gcc -o area 4_largest_rectangle_histogram.c
 * Execution: ./area
 *
 * @UJJWAL, 1910991390, 16/08/2021
 * Assignment 4 (Stacks and Queues)
 */


#include <stdio.h>
#define MAX 40

int stack[MAX];
int top = 0;

/*Function to push elements in the stack*/

void push(int value) {

    if(top == MAX)
    {
	printf("Stack Overflow");
    }
    stack[top++] = value;
}

/*Function to pop and remove topmost element from the stack*/

int pop() {

    int element;
    if(top == 0)
    {
	printf("Stack Underflow");
    }
    element = stack[top-1];
    top = top - 1;
    return element;
}

/*Function to return the topmost stack without removing it from the stack*/

int peek() {

   int element;

   if(top == 0)
   {
	printf("Stack Empty");
   }
   element = stack[top-1];
   return element;
}

/*Function to swap two given elements*/

void swap(int a[],int i,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

/*Function to sort given array
 *
 * parameters:
 * a[] = array of integers
 * n = size of array
 *
 */

void sort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
	for(int j = i+1; j < n; j++)
	{
	    if(a[i]>a[j])
	    {
	       swap(a,i,j);
	    }
	}
    }
}

/*Function to check the stack is empty or not*/

int is_empty() {

   if(top == 0)
   {
	return 1;
   }
   return 0;
}

int main() {

    int n;
    int area = 0;
    int value1;
    int value2;
    int i = 0;

    printf("Enter number of bars in histogram: ");
    scanf("%d",&n);
  
    int arr[n];
    
    printf("Enter heights: ");
    
    for(int i = 0; i < n; i++)
    {
	scanf("%d",&arr[i]);
    }

    sort(arr, n);
    
    for(int i = 0; i <n; i++)
    {
	push(arr[i]);
    }

    value1 = pop(); // popping the largest element
    value2 = pop(); // popping second largest element

    area = value2*2;
    
    /*Calculating maximum area rectangle*/

    while(i<n)
    {
        if(is_empty() == 0 && peek() == value2)
        {
	    area+=pop();
        }
	
	i++;
    }

    printf("The Maximum area is: %d",area);

    return 0;

}
