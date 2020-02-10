/*
Author: Mitch Hydrick
Date: 02/10/2020
Title: Performance Lab: Searching Exercise 2
Synopsis:
    - Find the difference between arrays:
    - Example output:
        Enter length of first array:4
        Enter 4 elements of first array
        1
        2
        3
        4
        Enter length of second array:4
        Enter 4 elements of second array
        2
        4
        5
        6
        The difference of the two array is:
        1
        3
        5
        6
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////
/* TO DO: Change main function to mimic the proper output shown above and utilize the diff() function */
////////////////////////////////////////////////////////////////////////////////////////////////////////

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

// linear searching function
int search_linear(int arr[], int num_to_find, int arr_size){

    int index = 0;

    // loop through array
        for (index; index <= arr_size; index++){
            if (arr[index] == num_to_find){
                return index + 1;
            }
        }
    return -1;
}

// diff() function gets the differences between two integer arrays
int diff(int arr1[], int arr1_size, int arr2[], int arr2_size){
    // get total size of both arrays to account for the potential max difference
    int size = arr1_size + arr2_size;
    // declare diff array to be returned
    int arr_diff[size];
    // initialize indexes
    int index = 0;
    int diff_index = 0;
    // declare found as the return for linear search function
    int found;
    // loop through array1 and searching through array2 for each index in array1
        for (index; index <= arr1_size; index++){
            found = search_linear(arr2, arr1[index], (sizeof(arr2)/sizeof(arr2[0])));
            if (found == -1){
                arr_diff[diff_index] = arr1[index];
                diff_index++;
            }
        }
        // reset index
        index = 0;
        for (index; index <= arr2_size; index++){
            found = search_linear(arr1, arr2[index], (sizeof(arr1)/sizeof(arr1[0])));
            if (found == -1){
                arr_diff[diff_index] = arr2[index];
                diff_index++;
            }
        }
    return arr_diff;
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