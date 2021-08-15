/* Program to extract byte n from word x
 *
 * Compilation: gcc -o getByte getByte.c
 * Execution: ./getByte
 *
 * @Ujjwal, 1910991390, 14/08/2021
 * Assignment 3 (Bits and Bytes)
 */

#include <stdio.h>

int getByte(int x, int n) {

    return ((x >> n*8) & 0xFF);
}

int main() {

    int value;
    int n;

    printf("Enter value : ");
    scanf("%x",&value);
    printf("Enter byte to extract");
    scanf("%d",&n);

    int result = getByte(value,n);
    printf("%d Byte is : %X",n,result);

    return 0;
}
