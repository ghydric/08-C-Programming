// Written by: Mitch Hydrick
// Date: 8 Jan 2020

// Synopsis: This program reads a string from stdin into a char array
//           of dimension 10 and then writes that string to stdout.


// import needed libraries
#include <stdio.h>

// start main function
int main(void) {
    
    char buff[10] = {0};                          // initialize character array
	printf("Enter a string:  ");                  // prompt user
	fgets(buff, sizeof(buff), stdin);             // get string entered from stdin and save to buffer
	printf("The buffer saved the following:  ");
	fputs(buff, stdout);                          // print out the string that was saved in buffer
	return 0;

} // end main function