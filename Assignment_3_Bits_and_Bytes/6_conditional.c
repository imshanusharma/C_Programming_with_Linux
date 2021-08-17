/* Program to implement conditional operator using bitwise operators
 *
 * Compilation: gcc -o conditional 6_conditional.c
 * Execution: ./conditional
 *
 * @UJJWAL, 1910991390, 17/08/2021
 * Assignment 3 (Bits and Bytes)
 */

#include <stdio.h>

int conditional(int x, int y, int z) {

    int temp1;
    int temp2;

    x = !x;           
    temp1 = ~x & y;    
    temp2 = x & z;   

    return temp1 | temp2;
}

int main() {

    printf("Answer : %d ", conditional(2, 4, 5));
    return 0;
}
