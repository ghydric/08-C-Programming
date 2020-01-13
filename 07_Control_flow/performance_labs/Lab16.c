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
    char multiple_phrases[128] = {0};
    multiple_phrases[-1] = '\0';
    int c = 0;

    // prompt user for input string that includes spaces
    printf("Enter a string with multiple spaces: \n");
    fgets(multiple_phrases, sizeof(multiple_phrases), stdin);
    printf("%s", multiple_phrases);
    printf("%s", multiple_phrases[c]);
    // loop through array and print out everything up to the new line character or NUL character
    while (multiple_phrases[c] != '\0')
        if (multiple_phrases[c] == ' '){
            printf("\n");
        } else {
            puts(multiple_phrases[c]);
        }
        // increment the index counter
        c++;

    return 0;
}
