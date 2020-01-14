/*
Author: Mitch Hydrick
Date: 1/13/2020
Title: Performance Lab 16 - "While loop"
Synopsis:
    1. Initialize a NUL terminated char array with multiple phrases separated by newlines (\n).
    2. Test the char array with puts().
    3. Write a WHILE loop that only prints the first line AND stops at a NUL character.
    NOTE: Stopping at the null character is a safety measure that accounts for arrays lacking a new line
*/

#include <stdio.h>

int main(void){

    // initialize NUL terminated character array and counter integer
    char multiple_phrases[] = "\tThis is the first line\n\tThis is the second line\n\tThis is the third line\0";
    int c = 0;

    printf("\nUsing puts to show the lines:\n\n");
    // show the user input with puts
    puts(multiple_phrases);

    printf("\nNow for the loop:\n\n");
    // loop through array and print out everything up to the new line character or NUL character
    while (multiple_phrases[c] != '\0' && multiple_phrases[c] != '\n'){
        
        // print out characters to screen
        putchar(multiple_phrases[c]);
        
        // increment the index counter 1
        c++;
    }

    printf("\n");
    return 0;
}
