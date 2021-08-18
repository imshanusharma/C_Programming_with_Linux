/* Function to check whether a number is negative or positive or zero using bits
 *
 * Compilation: gcc -o sign 3_sign.c
 * Execution: ./sign
 *
 * @UJJWAL, 1910991390, 16/08/2021
 * Assignment 3 (Bits and Bytes)
 */

#include <stdio.h>

int sign(int x) {

   return (x >> 31) - (-x >> 31);
    
}

int main() {

    int num;

    printf("Enter a number : ");
    scanf("%d", &num);

    printf("Answer : %d", sign(num));
}
