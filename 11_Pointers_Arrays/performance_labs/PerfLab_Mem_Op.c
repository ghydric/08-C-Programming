/*
Author: Mitch Hydrick
Date: 1/22/2020
Title: Performance Lab: Memory Operators "Reference Not Found"
Synopsis:
    1. Declare userInput, tempValue, and input_ptr as the same data type.
    2. Read user input into variable userInput.
    3. Ensure tempValue contains the same value as userInput utilizing one or more memory operators.
        - NOTE: tempValue = userInput; // NOT PERMITTED... use a memory operator
    4. Print the value and the pointer for each of the three variables in a human readable format.
    5. Locate those addresses in the "memory window". // NOT NECESSARY - USING VISUAL STUDIO CODE (MEMORY WINDOW IS ONLY IN VISUAL STUDIO)
    6. Submit your work to the appropriate location for instructor review.
        - NOTE: "input_ptr" should be a pointer variable
*/

// import necessary libraries
#include <stdio.h>

int main(void){

    // declare variables and pointer
    int userInput, tempValue, * input_ptr;
    
    // clear stdin buffer
    fflush(stdin);
    
    // get integer from user and store it in userInput variable
    printf("\nEnter an integer: ");
    scanf("%d", &userInput);
    
    // set input_ptr to address of userInput
    input_ptr = &userInput;
    
    // set tempValue to the value at userInput's memory location
    tempValue = *input_ptr;
    
    // print out the values and memory locations of all the variables and pointer
    printf("\nThe value of userInput is: %d", userInput);
    printf("\nThe address of userInput is: 0x%p\n", &userInput);
    printf("\nThe value of tempValue is: %d", tempValue);
    printf("\nThe address of tempValue is: 0x%p\n", &tempValue);
    printf("\nThe value of input_ptr is: %d", *input_ptr);
    printf("\nThe address of input_ptr is: 0x%p\n", input_ptr);

    return 0;
}



