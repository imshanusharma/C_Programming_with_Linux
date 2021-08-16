/* Program to print n even numbers of fibonacci series
 *
 * Compilation: gcc -o even 1_even_fibonacci.c
 * Execution: ./even
 *
 * @UJJWAL, 1910991390, 16/08/2021
 * Assignment 8 (Algorithm)
 */

#include <stdio.h>

/*Function to print only even numbers in fibonacci series n times*/

int even_fibonacci(int n) {

    if(n == 3)
    {
	return 2;
    }
    else if(n == 6)
    {
	return 8;
    }
    return 4*even_fibonacci(n-3) + even_fibonacci(n-6);
}

int main() {

    int n;

    printf("Enter the value of n : ");
    scanf("%d",&n);

    for(int i = 1 ; i <= n; i++)
    {
         printf("%d ",even_fibonacci(i*3));
    }

    return 0;
}
