// Written by: Mitch Hydrick
// Date: 8 Jan 2020

// Synopsis: 
//      Read a string into a char array.
//      Specify a field-width to protect against buffer overflow.
//      Stop reading at the first capital letter or new line.
//      Ensure the field-width leaves room for the nul-terminator.


// import needed libraries
#include <stdio.h>

// start main function
int main(void) {
    
    char buff[65] = {0};                          // initialize character array
	printf("Enter a string that is no more than 64 characters long:\n");
    scanf("%64[^A-Z\n]s", &buff);
    printf("\nThe buffer saved the following:\n%s", buff);
	return 0;

} // end main function