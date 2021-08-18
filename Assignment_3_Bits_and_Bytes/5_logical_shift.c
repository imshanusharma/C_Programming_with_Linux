/* Program to logically shift x to the right by n
 *
 * Compilation: gcc -o shift 5_logical_shift.c
 * Execution: ./shift
 *
 * @Ujjwal, 1910991390, 18/08/2021
 * Assignment 3 (Bits and Bytes)
 */

#include <stdio.h>

int logical_shift(int x, int n) {
   	
    unsigned int temp = (unsigned int) x;
   
    return (temp >> n);
}

int main() {

    int value;
    int n;

    printf("Enter the value in hexadecimal : ");
    scanf("%x",&value);

    printf("Enter the value of n: ");
    scanf("%d",&n);

    printf("Answer: %x",logical_shift(value,n));
    return 0;
}
