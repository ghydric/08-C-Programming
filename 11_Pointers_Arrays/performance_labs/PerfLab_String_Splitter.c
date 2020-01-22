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
#include <string.h>

// define MACROS
#ifndef ERROR_NULL_POINTER
#define ERROR_NULL_POINTER ((char*)-1)
#endif

#ifndef ERROR_ABUNDANT_POINTER
#define ERROR_ABUNDANT_POINTER ((char*)-2)
#endif

#ifndef ERROR_NULL_DELIMITER
#define ERROR_NULL_DELIMITER ((char*)-3)
#endif

// function declaration
char * split_the_string(char * string_ptr, char delimiter);

// main function
int main(void){

    // initialize string array and string pointer
    char string[27] = "First String;Second String";
    char * str_ptr = NULL;
    
    * str_ptr = split_the_string(string, ";");

    if (* str_ptr == NULL){
        printf("Something screwed up.");
    } else if (* str_ptr == -1){
        printf("ERROR: NULL POINTER");
    } else if (* str_ptr == -2){
        printf("ERROR: ABUNDANT POINTER");
    } else if (* str_ptr == -3){
        printf("ERROR: NULL DELIMITER");
    } else {
        printf("The string after the split: %s", * str_ptr);
    }

    return 0;
}

char * split_the_string(char * string_ptr, char delimiter){

    int delim_count = 0;
    int * returnValue_ptr = NULL;

    if (* string_ptr == NULL){
        return ERROR_NULL_POINTER;
    } else if (delimiter == NULL){
        return ERROR_NULL_DELIMITER;
    } 
    
    for (* string_ptr; * string_ptr <= strlen(* string_ptr); * string_ptr++){
        if (* string_ptr == delimiter){
            delim_count++;
            returnValue_ptr = (& * string_ptr + 1); 
        } else if (delim_count > 1){
            return ERROR_ABUNDANT_POINTER;
        }
        
    }

    return * returnValue_ptr;

}