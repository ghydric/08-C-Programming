/*
Author: Mitch Hydrick
Date: 1/21/2020
Title: Performance Lab 25: Conditional Compilation
Synopsis:
    1. Redefine EOF as 66 (without compiler warnings)
    2. Use preprocessor directive(s) to:
        - Only compile in "release" and only compile if _INC_STDIO is defined
        - Prints the name of a MACRO and also print the integer value of that MACRO
        - Use a #else 'fall through' for ease of use and safety
    3. Use your preprocessor directives on FOPEN_MAX, FILENAME_MAX, and EOF
*/

// import necessary libraries
#include <stdio.h>

// if EOF is already defined, undefine it, then redefine it to 66
#ifdef EOF
    #undef EOF
#endif
#define EOF 66

// define release and _inc_stdio so the code will compile
#define RELEASE 1
#define _INC_STDIO 1

// if both release and _inc_stdio are not defined, do not compile, otherwise continue with program
#if defined(RELEASE) && defined(_INC_STDIO)

// print_macro prints out the macro name and the integer value of the macro
#define PRINT_MACRO(x) printf(#x " is %d\n", x)

int main(void){
    PRINT_MACRO(FOPEN_MAX);
    PRINT_MACRO(FILENAME_MAX);
    PRINT_MACRO(EOF);
}
#else
printf("Error");
#endif