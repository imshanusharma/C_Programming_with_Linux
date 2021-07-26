/* Program to analyze the runtime of bubble sort algorithm
 *
 * Compilation: gcc -o runtime bubble_sort_analysis.c
 * Execution : ./runtime
 *
 * @Ujjwal, 1910991390, 26/7/2021
 * Assignment (Homework)
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* Function to sort the array using bubble sort
 * 
 * Paramaters
 * a : array of integers
 * n : number of elements in array
 * 
 * Return
 * Sorted Array
 */

void bubble_sort(int a[], int n) {

    int temp;
    for(int i = 0; i < n - 1; i++) {
    
        for(int j = 0; j < n - i - 1; j++) {
		
	    if(a[j] > a[j+1]) {
	    
	        a[j] = temp;
		a[j] = a[j+1];
		a[j+1] = temp;
	    }	    
        } 
    }
}

int main() {

    int n;
    int elapsed;

    printf("Enter number of random elements you want in array:");
    scanf("%d",&n);
    
    int a[n];

    for(int i = 0; i < n; i++) {
    
        a[i] = rand();
    }
    /*Uncomment below part to calculate time complexity for the Ascending order (Best Case)*/
    /* int temp1;
     for(int i = 0; i < n; i++) {
    
         for(int j = 0; i < n-i-1; j++) {
	 
	     if(a[j] > a[j+1]) {
	     
	         temp1 = a[j];
  	       	a[j] = a[j+1];
 		a[j+1] = temp1;
	    }  
	}
    }*/
	
    /*Uncomment below part to calculate runtime complexity for the Descending order*/

   /* int temp1;
    for(int i=0;i<n;i++) {
    
       for(int j=i+1;j<n;j++) {
       
           if(a[i] < a[j]) {
	       
	       temp1 = a[i];
	       a[i] = a[j];
	       a[j] = temp;
	   }
       }
    }*/


    struct timeval e;
    gettimeofday(&e, NULL);
    long long start_time = e.tv_sec*1000LL + e.tv_usec/1000;
    bubble_sort(a,n);
    gettimeofday(&e, NULL);
    long long end_time = e.tv_sec*1000LL + e.tv_usec/1000;
    elapsed = end_time - start_time;
    printf("Start Time : %lld\nEnd Time : %lld\n",start_time,end_time);
    printf("Elapsed : %d",elapsed);
    
    return 0;
}

