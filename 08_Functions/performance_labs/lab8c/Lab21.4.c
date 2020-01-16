/*
Author: Mitch Hydrick
Date: 1/16/2020
Title: Performance Lab 21.4: Recursive Palindrome
Synopsis:
    1. Write a recursive function that returns a value of 1 if its string argument is a palindrome, 0 otherwise.
    - Notice that in palindromes such as level, deed, sees, and madam...the first letter matches the last.
*/

// import necessary libraries
#include <stdio.h>
#include <string.h>

// function that checks if a string is a palindrome
// returns 1 if it is a palindrome, and 0 if it is not
int is_palindrome(char * string_to_check){
    // leading index
    static int index_1 = 0;
    // counter is for decrementing the trailing index each iteration
    static int counter = 1;
    // get length of the string
    int size = strlen(string_to_check);
    // trailing index
    int index_2 = size - counter;
    /* for testing
    printf("The size of %s is: %d\n", string_to_check, size);
    printf("The first pointer is at this character: %c\n", string_to_check[index_1]);
    printf("The last pointer is at this character: %c\n", string_to_check[index_2]);
    printf("The first pointer is at position: %d\n", index_1);
    printf("The last pointer is at position: %d\n", index_2);
    */
    // if the first index becomes greater than or equal to the second index, then it
    // made it through the whole string without mismatches; therefore, it is a palindrome
    if (index_1 >= index_2){
        //printf("The first pointer is equal to or greater than the last pointer.\n"); // for testing
        return 1;
    } else if (string_to_check[index_1] == string_to_check[index_2]){ // if first index character matches the trailing index character,
        index_1 += 1;                                                 // increment leading index and counter by 1
        counter += 1;
        //printf("The counter is at: %d\n", counter); // for testing
        return is_palindrome(string_to_check);                        // then recursively call the itself
    } else {  // otherwise there is a mismatch
        //printf("There is a mismatch. Not a palindrome.\n"); // for testing
        return 0;
    }
}

// main function
int main(void){
    // initialize a zeroed 128 byte character array
    char new_string[128] = {0};
    
    // flush the input buffer, then get a string from the user
    printf("Enter in a string to check: \n");
    fflush(stdin);
    scanf("%127s", &new_string);

    // call function and get result
    int end_result = is_palindrome(new_string);

    // print out appropriate result
    if (end_result == 1){
        printf("%s is a palindrome.", new_string);
    } else {
        printf("%s is not a palindrome", new_string);
    }

    return 0;
}