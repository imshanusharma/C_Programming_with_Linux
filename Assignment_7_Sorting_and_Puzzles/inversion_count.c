/* Program to find inversion count of an array
 *
 * Compilation: gcc -o count inversion_count.c
 * Execution: ./count
 *
 * @UJJWAL, 1910991390, 10/08/2021
 * Assignment 7 (Sorting and puzzles)
 */

#include <stdio.h>

/*Function to find inversion count of given array
 *
 * parameters:
 * array[] = an array of integers
 * size = size of array
 *
 * return:
 * inversion count
 */

int inversion_count(int array[], int size) {

    int count = 0;

    for(int i = 0; i < size-1; i++)
    {
	for(int j = i+1; j < size; j++)
	{
	    if(array[i]>array[j] && i < j)
		count++;
	}
    }
    
    return count;
}

int main() {

    int size;

    printf("Enter the elements in array : ");
    scanf("%d", &size);

    int array[size];

    printf("Enter array Elements : ");

    for(int i = 0; i < size; i++)
    {
	scanf("%d",&array[i]);
    }

    printf("Inversion count is : %d",inversion_count(array,size));

    return 0;
}
