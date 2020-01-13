/*
Author: Mitch Hydrick
Date: 1/13/2020
Title: Performance Lab 11 - "If Statement"
Synopsis:
    1. Initialize a char array to zero.
    2. Safely store a user-input string in the char array.
    3. Safely print the string IF the following conditions are both true:
        - The first element greater than or equal to decimal value 32.
        - The first element is less than decimal value 126.
    NOTE: decimal values 32-126 represent printable ASCII characters
*/

#include <stdio.h>

int main(void){
    
    // initialize zeroed character array
    char my_char_array[128] = {0};
    
    // prompt user for a number and save it in character array
    printf("Please input a string: \n");
    fgets(my_char_array, sizeof(my_char_array), stdin);
    
    // print the first element for testing
    printf("The first element is: %c\n", my_char_array[0]);
    printf("The first element as a decimal is: %d\n", (int) my_char_array[0]);
    
    // if the first element is a printable ASCII character, print it out, otherwise print a statement
    if(my_char_array[0] >= 32 && my_char_array[0] < 127){
        printf("The string you supplied was: %s", my_char_array);
    } else{
        printf("The first element was not a printable ASCII character.");
    }

    return 0;
}