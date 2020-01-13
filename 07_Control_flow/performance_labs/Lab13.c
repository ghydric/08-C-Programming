/*
Author: Mitch Hydrick
Date: 1/13/2020
Title: Performance Lab 13 - "Else-If Statement" Swap the largest Number
Synopsis:
    1. Initialize ONLY three unsigned int variables to 0.
    2. Safely scan user input into the variable #1 and #2 utilizing a single line.
    3. Using a single ELSE-IF statement:
        - If variable #1 is equal to variable #2, print an ERROR.
        - Otherwise, exchange the value of the largest variable with variable #3 while preserving the other value.
    4. Print the values of all three variables if the SUM of the three variables is greater than 2 regardless of the previous ELSE-IF statement.
*/

#include <stdio.h>

// function that swaps 2 numbers using XOR
void swap_xor(int *m, int *n){
    
    // XOR swap
    *m = *m ^ *n;
    *n = *m ^ *n;
    *m = *m ^ *n;

}

// main function
int main(void){

    // initialize 3 global unsigned integer variables
    __UINT32_TYPE__ num1 = 0;
    __UINT32_TYPE__ num2 = 0;
    __UINT32_TYPE__ num3 = 0;

    // prompt user for 2 integers
    printf("Enter 2 numbers separated by a space (ie:00 00): ");
    scanf("%02d %02d", &num1, &num2);

    // if numbers entered are equal, print error statement
    // otherwise, swap the greater of the two with num3 using XOR
    if (num1 == num2){
        printf("Error: The two numbers cannot be equal. Try again.\n");
    } else if (num1 > num2){
        printf("The numbers before swapping:\nNum1 = %d\nNum2 = %d\nNum3 = %d\n", num1, num2, num3);
        swap_xor(&num1, &num3);
        // if not using function above:
        //num1 = num1 ^ num3;
        //num3 = num1 ^ num3;
        //num1 = num1 ^ num3;
    } else {
        printf("The numbers before swapping:\nNum1 = %d\nNum2 = %d\nNum3 = %d\n", num1, num2, num3);
        swap_xor(&num2, &num3);
        // if not using function above:
        //num2 = num2 ^ num3;
        //num3 = num2 ^ num3;
        //num2 = num2 ^ num3;
    }

    // if the sum of all the nums is greater than 2, print each num out
    if (num1 + num2 + num3 > 2){
        if (num1 == 0){
            printf("The numbers after swapping Num1 and Num3:\nNum1 = %d\nNum2 = %d\nNum3 = %d", num1, num2, num3);
        } else if (num2 == 0) {
            printf("The numbers after swapping Num2 and Num3:\nNum1 = %d\nNum2 = %d\nNum3 = %d", num1, num2, num3);
        } else {
            printf("The numbers were:\nNum1 = %d\nNum2 = %d\nNum3 = %d", num1, num2, num3);
        }
    }

    return 0;
}