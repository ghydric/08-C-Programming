/*
Written by: Mitch Hydrick
Date: 8 Jan 2020

Synopsis: This program gets the first character of user input, displays it to the screen, 
          then displays the next character to the screen.
*/

// import needed libraries
#include <stdio.h>

// start main function
int main(void) {
    
    int userInput = 0;                      // initialize userInput
	printf("Enter a character:  ");         // prompt user
    userInput = getchar();                  // gets first character from input
	printf("Your character was:  ");        
	putchar(userInput);                     // print out the character that was just entered
    printf("\nThe next character is: ");
    putchar(userInput + 1);                 // print out the next character
	return 0;

} // end main function