/* Program to illustrate BitAnd (&) operator in c using only not (~) and or (|)
 *
 * Compilation : gcc -o bitand BitAnd.c
 * Execution : ./bitand
 *
 * @Ujjwal, 1910991390, 02/08/2021
 * Assignment 3 (Bits and Bytes)
 */

#include <stdio.h>

/*Function to calculate bitAnd using ~ and | only */

int bitAnd(int x, int y) {

    int result

    x = ~x;             // ops1 : not (~)
    y = ~y;             // ops2 : not (~)
    result = x|y;       // ops3 : or  (|)
    result = ~result;   // ops4 : not (~)

    return result;
}

int main() {
 
    int num1;
    int num2;

    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number: ");
    scanf("%d",&num2);

    int result = bitAnd(num1,num2);
    printf("Result is: %d",result);
    return 0;
}
