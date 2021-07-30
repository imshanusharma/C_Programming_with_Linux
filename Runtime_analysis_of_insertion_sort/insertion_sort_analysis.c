/* Program to analyse runtime complexity of insertion sort algorithm
 *
 * Compilation: gcc -o runtime insertion_sort_analysis.c
 * Execution: ./runtime
 *
 * @Ujjwal, 1910991390, 29/07/2021
 * Assignment (Runtime_analysis of insertion sort)
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* Function to sort array using insertion sort algorithm
 *
 * parameter
 * arr[] : an array of integers
 * n : size of array
 *
 * Return
 * sorted array
 */

void insertion_sort(int arr[], int n)
{
    int val;
    int j;
    int i; 

    for(i = 1; i < n; i++)
    { 
	val = arr[i];
        j = i - 1;

	while(j >= 0 && arr[j] > val){
	
	    arr[j + 1] = arr[j];
	    j = j - 1;
	}
	arr[j + 1] = val;
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

    //ascending(arr,n);
    //descending(arr,n);

    struct timeval e;
    gettimeofday(&e,NULL);
    long long start_time = e.tv_sec*1000LL + e.tv_usec/1000;
    insertion_sort(arr,n);
    gettimeofday(&e,NULL);
    long long end_time = e.tv_sec*1000LL + e.tv_usec/1000;
    int elapsed = end_time - start_time;
     
    printf("Time Elapsed : %d",elapsed);

    return 0;

}
