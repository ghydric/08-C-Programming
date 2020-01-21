/*
Author: Mitch Hydrick
Date: 1/15/2020
Title: Performance Lab 20: Function - "Healthy Substitutions"
Synopsis:
    1. Create the following function:
        - int replace_character(char * string, const char findThisChar, const char replaceItWithThis);
    2. Function must have the following:
        a. Return Value - Number of characters replaced
        b. Parameters:
            - Pointer to a null-terminated string
            - Character to find
            - Character to replace it with
        c. Purpose - Replace all occurences of findThisChar with replaceItWithThis
        d. Use pre-defined return values as indicated in shell code
*/

// import necessary libraries
#include <stdio.h>
// initialize global scope string to be modified
char string_to_modify[] = "The quick brown fox jumps over the lazy dog.";

int replace_character(char * string, const char findThisChar, const char replaceItWithThis);

int main(void){
    int num_replaced = replace_character(&string_to_modify, 'o', '_');
    printf("Replaced %d characters\nNew string: %s", num_replaced, string_to_modify);

    return 0;
} 

int replace_character(char * string, const char findThisChar, const char replaceItWithThis){
    if (string == NULL){
        return -1;
    } else {
        int characters_replaced = 0;
        for (*string; *string != NULL; *string++){
            if (*string == findThisChar){
                *string = replaceItWithThis;
                characters_replaced++;
            }
        }
        return characters_replaced;
    }
    
}