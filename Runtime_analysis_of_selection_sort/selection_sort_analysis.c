/* Program to analyse runtime complexity of Selection sort
 *
 * Compilation: gcc -o runtime selection_sort_analysis.c
 * Execution: ./runtime
 *
 * @Ujjwal, 1910991390, 29/07/2021
 * Assignment (Runtime_analysis of selection sort)
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* Function to swap two numbers*/

void swap (int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to sort array using selection sort algorithm
 *
 * parameter
 * arr[] : an array of integers
 * n : size of array
 *
 * Return
 * sorted array
 */

void selection_sort(int arr[], int n)
{
    int min;

    for(int i = 0; i < n-1; i++)
    {
	min = i;

        for(int j = i+1; j < n; j++)
	{
            if(arr[min] > arr[j])
	    {
	        min = j;
	    }
	}
	swap(&arr[min],&arr[i]);
    }
}

/*Function to sort array in ascending order using bubble sort for checking runtime complexity of sorted array input case*/

void descending(int arr[], int n)
{
    int temp;

    for(int i  = 0; i < n-1; i++)
    {
	for(int j  = i+1; j < n; j++)
	{
            if(arr[i] < arr[j])
	    {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	    }
	}
    }

}

/*Function to sort array in descending order to check runtime complexity of reversed array input*/

void ascending(int arr[], int n)
{
    int temp;

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
	{
	    if(arr[i] > arr[j])
	    {
	        temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	    }
	}
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
	arr[i] = rand()/100000;
    }
    
    /*Uncomment below part to check runtime for sorted/reversed array input*/

   // ascending(arr,n);
   // descending(arr,n);

    struct timeval e;
    gettimeofday(&e,NULL);
    long long start_time = e.tv_sec*1000LL + e.tv_usec/1000;
    selection_sort(arr,n);
    gettimeofday(&e,NULL);
    long long end_time = e.tv_sec*1000LL + e.tv_usec/1000;
    int elapsed = end_time - start_time;
    
    printf("Time Elapsed : %d",elapsed);

    return 0;

}
