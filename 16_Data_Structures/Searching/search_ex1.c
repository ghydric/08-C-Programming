/*
Author: Mitch Hydrick
Date: 02/10/2020
Title: Performance Lab: Searching Exercise 1
Synopsis:
    - Create a program to search this array: {4, 6, 1, 2, 5, 3} and search for a particular number in the array.
    - Example output if the input array is {4, 6, 1, 2, 5, 3} and if the element searched is 6:
        - Found 6 at position 2 of the array.
*/

// import necessary libraries
#include <stdio.h>

// function that clears all of the input buffer so no erroneous characters will be part of the input
int flush_buffer(void){
    
	int c = getchar();  // random variable declared to be a placeholder for any erroneous characters in the input buffer to be processed
	while (c != '\n' && c != '\r' && c != EOF){
        c = getchar();
    }
    return 0;
}

int search_linear(int arr[], int num_to_find, int arr_size){

    printf("Starting search...\n");
    int index = 0;

    // loop through array
        for (index; index <= arr_size; index++){
            if (arr[index] == num_to_find){
                return index + 1;
            }
        }
    return -1;
}

int main(void){

    // initialize number array, user input, and position
    int num_array[6] = {4, 6, 1, 2, 5, 3};
    int user_input;
    int position = 0;
    
    // gather user input
    printf("Please enter a number to search for: ");
    scanf("%d", &user_input);
    printf("Retrieved input.\n");
    // if error taking input, exit
    if (!user_input){
        printf("Error retrieving input\n");
        return -1;
    } else {
        // complete linear search on array for user input
        position = search_linear(num_array, user_input, (sizeof(num_array)/sizeof(num_array[0])));
        
        // if not found, print out error
        if (position == -1){
            printf("Could not find %d\n.", user_input);
        } else { // otherwise, print out the position it was found at
            printf("Found %d at position %d in the array.\n", user_input, position);
        }
    }

    // flush the buffer
    flush_buffer;
    
    return 0;
}