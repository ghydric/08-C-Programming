/*
Author: Mitch Hydrick
Date: 10 Jan 2020
Title: Student Performance Labs
Synopsis:
    1. Write a program to shift the entered number by three bits left and display the result.
    2. Write a program to shift the entered number by five bits right and display the result.
*/

// include necessary libraries
#include <stdio.h>

// start main program
int main(void){
    
    // instantiate number
    __UINT32_TYPE__ num;
    
    // prompt user for integer
    printf("Enter a positive integer: ");
    scanf("%lu", &num);
    printf("You entered: %lu\n", num);
    // print out the integer after shifting
    printf("The number after shifting left 3: %lu\n", num << 3);
    printf("The number after shifting right 5: %lu", num >> 5);
    
    // end program
    return 0;

}