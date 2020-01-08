
// Written by: Mitch Hydrick
// Date: 8 Jan 2020

// Synopsis: This program gets the first character of user input, displays it to the screen, 
//          then displays the previous character to the screen.


// import needed libraries
#include <stdio.h>

// start main function
int main(void) {
    
    int userInput = 0;                          // initialize user input
	printf("Enter a character:  ");             // prompt user
	userInput = getc(stdin);                    // get first character entered
	printf("Your character was:  ");
	putc(userInput, stdout);                    // print out the character that was just entered
    printf("\nThe previous character is: ");
    putc(userInput - 1, stdout);                // print out the previos character
	return 0;

} // end main function