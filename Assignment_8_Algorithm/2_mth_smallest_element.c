/* Program to find Mth smallest number in an unsorted array of size N
 *
 * Compilation: gcc -o element 2_mth_smallest_element.c
 * Execution: ./element
 *
 * @Ujjwal, 1910991390, 16/08/2021
 * Assignment 8 (Algorithm)
 */

#include <stdio.h>

/*Function to swap given two elements of array*/

void swap(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

/*Function to sort array using quick sort, Runtime complexity will be O(nlogn)*/

void quick_sort(int a[], int left, int right)
{
    /*Assuming first element to be pivot*/

    int pivot = left;
    int final_pivot = left;
 
    /*If end of array reached*/

    if(left >= right)
    {
	return;
    }
   
    /*Finding correct position of pivot in the array*/

    for(int i = left + 1; i <= right; i++)
    {
	if(a[pivot] > a[i])
	{
	    swap(a,i,++final_pivot);
	}
    }

    swap(a,pivot,final_pivot);         //moving pivot to correct position
    quick_sort(a,left,final_pivot-1);  //recursive call to sort array elements to the left of pivot
    quick_sort(a,final_pivot+1,right); //recursive call to sort array elements to the right of pivot
}

int main() {

    int size;
    int M;

    printf("Enter the size of array : ");
    scanf("%d",&size);

    int array[size];
   
    for(int i = 0; i < size; i++)
    {
	scanf("%d",&array[i]);
    }

    printf("Enter the value of M (Mth smallest element) : ");
    scanf("%d",&M);

    quick_sort(array,0,size);
        
    printf("The Mth smallest element is : %d",array[M]);

    return 0;
}
