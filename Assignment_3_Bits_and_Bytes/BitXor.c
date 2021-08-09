/* Program to calculate bitXor using only ~ and &
 *
 * Compilation: gcc -o xor BitXor.c
 * Execution: ./xor
 *
 * @UJJWAL, 1910991390, 09/08/2021
 * Assignment 3 (Bits and Bytes)
 */

#include <stdio.h>

/*Function to calculate bitXor using only not (~) and and (&) operator*/

int bitXor(int x, int y)
{
    int answer;
    x = ~x;            //ops1 : not (~)
    answer = x & y;    //ops2 : and (&)
    return answer;
}

int main() {

    int num1;
    int num2;

    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);

    printf("Answer : %d", bitXor(num1, num2));
    return 0;
}
