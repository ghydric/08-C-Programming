/*
Author: Mitch Hydrick
Date: 02/10/2020
Title: Performance Lab: Search in a file
Synopsis:
    - Search the file numbers.txt that has a sorted 2D array. 
    - Create a program to search for a number from the file and also display something if the number is not found.
*/

// import necessary libraries
#include<stdio.h>
#include<stdlib.h>

// define FILENAME MACRO
#ifndef FILENAME
#define FILENAME "numbers.txt"
#endif

// function that searches a file
int search_file(char * fname, int key){
    
    // declare numbers file
    FILE * numbers;

    // initialize number of rows and columns
    int num_cols = 6;
    int num_rows = 5;

    // initialize data array that will hold the numbers gathered from the file
    int data[num_rows][num_cols];

    // open file for reading
    numbers = fopen(fname, "r");

    if (numbers == NULL){
        printf("Error getting data from file.\n");
        return -2;
    } else {
        printf("Reading in data now...\n");
        // read in all the data from numbers.txt and store into 2d array
        for (int row = 0; row < num_rows; row++){
            for (int col = 0; col < num_cols; col++){
                fscanf("%d", &data[row][col]);
                printf("%d, ", data[row][col]);
            }
            
        }
        printf("Size of array: %d", (sizeof(data)/sizeof(data[0][0])));
        // close file
        fclose(numbers);

        
        // perform search for key on data array, if found, return row and column
        for (int row = 0; row < num_rows; row++){
            for (int col = 0; col < num_cols; col++){
                printf("R%d,C%d: %d ; ", row, col, data[row][col]);
                if (data[row][col] == key){
                    return (row + 1), (col + 1);
                }
            }
        }
    }
    // otherwise return -1 for not found
    return -1, -1;
}

// main function
int main(void){

    // define search key, found_row, and found_col
    int search_key;
    int found_row;
    int found_col;

    // prompt user for a number to search the file for
    printf("Please enter a number to search for: ");
    scanf("%d", &search_key);

    // search the file for the search key
    found_row, found_col = search_file(FILENAME, search_key);
    printf("found row: %d", found_row);
    printf("found col: %d", found_col);

    if (found_row == -1 && found_col == -1){
        printf("Search key was not found in the numbers file.\n");
    } else {
        printf("Found %d at row: %d and column: %d of the numbers file.\n", search_key, found_row, found_col);
    }

    // exit program
    return 0;
}