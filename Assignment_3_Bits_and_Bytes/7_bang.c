/* Program to find bang of a number using only bitwise operators
 *
 * Compilation: gcc -o bang 7_bang.c
 * Execution: ./bang
 *
 * @UJJWAL, 1910991390, 18/08/2021
 * Assignment 3 (Bits and Bytes)
 */

#include <stdio.h>

/*Function to compute bang(n)*/

int bang(int n) {

    int temp = ~n;
    int temp2 = temp + 1;
    temp2 = ~temp2;

    return (temp2 & temp) & 1;
}

int main() {

    int n;

    printf("Enter number: ");
    scanf("%d",&n);

    printf("Answer is : %d",bang(n));

    return 0;
}
