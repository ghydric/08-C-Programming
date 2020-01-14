/*
Author: Mitch Hydrick
Date: 1/13/2020
Title: Performance Lab 17 - "Do-While loop"
Synopsis:
    1. Initialize a 26 element int array to 0.
    2. Initialize a char variable to 0.
    3. Use a DO-WHILE loop to input, but not store, a string one character at a time from stdin without scanf()!!
    4. Each time a character is entered:
        - convert the character to upper case using toupper()
        - increment the corresponding array element if the user input is a letter
        - Ensure non-letters (i.e. Ctrl-D, tab) are safely handled
    5. End the loop when a newline is read.
    6. Print the results using a for loop ().
*/

#include <stdio.h>

int main(void){

    // initialize 26 element integer array, char variable as a holder for the user input, and int i variable for index counter
    int my_array[26] = {0};
    char c = 0;
    int i = 0;

    do {
        // flush the input buffer
        fflush(stdin);
        
        // get character from user
        printf("Enter a letter: ");
        c = fgetchar();
        
        // if character entered is either an upper or lowercase letter of the alphabet
        if ((int)c >= 65 && (int)c <= 90 || (int)c >= 97 && (int)c <= 122){
            // if it is a lowercase letter, convert to uppercase
            if ((int)c >= 97 && (int)c <= 122){
                c = toupper(c);
            }
            // increment the appropriate letter in the array
            my_array[c - 65]++;
        } 

        // if character entered is a new line character
        else if (c == '\n'){
            break;
        }
        
        // character entered was not an upper or lowercase letter of the alphabet
        else {
            printf("You did not enter a valid letter.\n");
            continue;
        }

    } while (c != '\n');

    printf("Below shows the amount of times each letter was entered:\n");
    // print out the array using a for loop
    for (i = 0; i < 26; i++){
        printf("%c: %d\n", i + 65, my_array[i]);
    }

    return 0;
}