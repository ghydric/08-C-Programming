/*
Author: Mitch Hydrick
Date: 1/22/2020
Title: Performance Lab: String Splitter
Synopsis:
    1. Create a program based on the following function declaration:
        - char * split_the_string(char * string_ptr, char delimiter);
    2. Return value - char pointer to the second string.
    3. Parameters:
        - string_ptr - Pointer to a null terminated string
        - delimiter - Character that divides the two strings
    4. Purpose - Split one string into two at a delimiter char.
    5. Requirements:
        - Only Address Arithmetic is permitted on string_ptr
        - string_ptr if delimiter is not found
        - Return ERROR_NULL_POINTER if string_ptr has more that one occurrence of delimiter
        - Return ERROR_NULL_DELIMITER if the delimiter is '\0' (0x0)
    NOTE: The error codes for this lab are MACROS #defined as: 
        - #define ERROR_NULL_POINTER ((char*)-1)
        - #define ERROR_ABUNDANT_POINTER ((char*)-2)
        - #define ERROR_NULL_DELIMITER ((char*)-3)
*/

// import necessary libraries
#include <stdio.h>

// define MACROS
#ifndef ERROR_NULL_POINTER
#define ERROR_NULL_POINTER "The input string was NULL or empty.\n"
#endif

#ifndef ERROR_ABUNDANT_POINTER
#define ERROR_ABUNDANT_POINTER "Too many delimiters found in the input string.\n"
#endif

#ifndef ERROR_NULL_DELIMITER
#define ERROR_NULL_DELIMITER "The delimiter is NULL."
#endif

// function declaration
char * split_the_string(char * string_ptr, char delimiter);

// main function
int main(void){

    // initialize string arrays and string pointer
    char string_1[49] = "This string is first; it has only one semicolon.";
    char string_2[66] = "This string is next; string_2 is the name; it has two semicolons.";
    char string_3 = NULL;
    char string_4[48] = "This string is fourth; it has a NULL delimiter.";
    char * str_ptr = NULL;
    char * string_array[4] = {string_1, string_2, string_3, string_4};

    // loop through all of the strings and try to split them
    for (int i = 0; i < 4; i++){
        printf("The initial string is: %s\n", string_array[i]);
        if (i == 3){
            str_ptr = split_the_string(string_array[i], NULL);
        } else {
            str_ptr = split_the_string(string_array[i], ';');
        }

        printf("%s\n", str_ptr);
    }

    return 0;
}

char * split_the_string(char * string_ptr, char delimiter){

    int delim_count = 0;
    int * returnValue_ptr = NULL;

    //printf("The delimiter is: %c\n", delimiter);
    //printf("The string_ptr is: %s\n", string_ptr);

    if (string_ptr == NULL){
        return ERROR_NULL_POINTER;
    } else if (delimiter == NULL){
        return ERROR_NULL_DELIMITER;
    } 
    
    for (; * string_ptr != NULL; * string_ptr++){
        if (* string_ptr == delimiter){
            delim_count++;
            returnValue_ptr = (& * (string_ptr + 1));
        } else if (delim_count > 1){
            return ERROR_ABUNDANT_POINTER;
        }
        
    }
    return returnValue_ptr;
}