/*
Author: Mitch Hydrick
Date: 1/21/2020
Title: Performance Lab 24: Preprocessor Directives
Synopsis:
    1. Write a C program with preprocessor directives to:
        - Combine two string literals
        - Wrap those string literals in quotes
        - Define a constant buffer size of 64
    2. Define an array:
        - Of standard buffer size
        - Assign the wrapped string literals to the array
    3. Print the array
*/

// import necessary libraries
#include <stdio.h>

// define macros
#define STRING(a) #a
#define TO_STRING(a) STRING(a)
#define CONCAT(x, y) x##y
#define CONCATENATE(a, b) CONCAT(a, b)
#define BUFFSIZE 64

int main(void){

    char string_array[BUFFSIZE] = TO_STRING(CONCATENATE(This is string 1, This is string 2));
    printf("Your string array is: %s", string_array);
}