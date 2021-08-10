/* Program to find the maximum number in k-sized sliding window
 *
 * Compilation : gcc -o max 6_maximum_sliding_window.c
 * Execution : ./maximum
 *
 * @Ujjwal, 1910991390, 10/08/2021
 * Assignment 4 (Stacks and Queues)
 */

#include <stdio.h>

#define MAX 20

/*Defining global variables*/

int queue[MAX];
int head = 0;
int tail = 0;

/*Function to dequeue element from the queue*/

void dequeue() {

    int i=0;
    if(tail == head)
    {
	printf("tail is empty");
    }
    while(i < tail)
    {
	queue[head + i] = queue[head + i + 1];
	i++;
    }
    tail--;

}

/*Function to add element to the queue*/

void enqueue(int value)
{
    if(tail == MAX)
    {
	printf("Queue is full");
	return;
    }
    queue[tail++] = value;
}

/* Function to find the maximum number in k-sized sliding window
 *
 * parameters:
 * a[] = array of integers
 * n = size of array
 * k = max size of window
 *
 * return
 * maximum element in the window
 */

void max_sliding_window(int a[], int n, int k)
{
    int max = 0;
    int val;
    
    //if window size is 1, each element will be the maximum, so print whole array

    if(k == 1)
    {
        for(int i = 0; i < n; i++)
	{
	    printf("%d ",a[i]);
	}
	return;
    }
   
    int temp = 0;
   
    //finding maximum element in k-sized window, only till our queue size remains greater than k.

    while(tail >= head + k)
    {
        for(int i = 0; i < k; i++)
        {
	    val = queue[temp];

	    if(val > max)
	    {
                max = val;
	    }
	    temp++;
        }

        printf("%d ",max);

	temp = 0;

	dequeue();
    }
}

int main() {

    int n;
    int k;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter array elements: "); 

    for(int i = 0; i < n; i++)
    {
	scanf("%d", &arr[i]);
    }

    printf("Enter the value of k : ");
    scanf("%d",&k);

    for(int i = 0; i < n; i++)
    {
	enqueue(arr[i]);
    }

    max_sliding_window(arr,n,k);
    return 0;
}
