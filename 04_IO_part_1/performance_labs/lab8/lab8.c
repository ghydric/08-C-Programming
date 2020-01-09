// Written by: Mitch Hydrick
// Date: 8 Jan 2020

// Synopsis: This program reads a string from stdin into a char array
//           of dimension 10 and then writes that string to stdout.


// import needed libraries
#include <stdio.h>

// flush the buffer
int flush_buffer() {
    fseek(stdin,0,SEEK_END);
    return 0;
}

// start main function
int main(void) {
    
    // initialize first, middle, and last name char arrays
    char f_name[21] = {0};
	char m_name[21] = {0};
    char l_name[21] = {0};
    
    // initialize two numbers to be multiplied
    int num1 = 0;
    int num2 = 0;

    printf("Enter first, middle, and last name separated by <tab>s:\n");                  // prompt user
	scanf("%20s\t%20s\t%20s", &f_name, &m_name, &l_name);
	printf("%s\t\n%s\t\n%s", f_name, m_name, l_name);
	printf("\n\nEnter two numbers separated by *:\n");
    flush_buffer();
    scanf("%d%*c%d", &num1, &num2);
	printf("The result of %d multiplied by %d is %d.", num1, num2, num1*num2);
    
    return 0;

} // end main function