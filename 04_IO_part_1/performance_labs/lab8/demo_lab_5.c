// Written by: Mitch Hydrick
// Date: 8 Jan 2020
// Title: Formatted Input (Numbers)
// Synopsis:
//      Read three ints, representing the date, from one line
//      Format the input so the integers are separated by a dash (-) as <mm>-<dd>-<yyyy>
//      Output the results as a date with leading zeros <mm>/<dd>/<yyyy>
//      Specify the field width of the output appropriately


// import needed libraries
#include <stdio.h>

// start main function
int main(void) {
    
    // initialize month, day, and year variables
    int month = 0;
    int day = 0;
    int year = 0;

    // prompt user, get input from user, then display the newly formatted date to the screen
    printf("Please enter a date (mm-dd-yyyy): ");
    scanf("%2d-%2d-%4d", &month, &day, &year);
    printf("\nThe date you entered was: %02d/%02d/%04d", month, day, year);
    
	return 0;

} // end main function