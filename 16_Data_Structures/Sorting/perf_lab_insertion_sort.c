/*
Author: Mitch Hydrick
Date: 02/11/2020
Title: Performance Lab: Insertion Sort
Synopsis:
    - Write a C program that implements the insertion sort algorithm. 
    - Create it with the following example output:
        Enter the number of elements in the array: 5
        Enter the elements of the array: 500 1 50 23 76
        The sorted array is:
        1 23 50 76 500
*/

// import necessary libraries
#include<stdio.h>

// function that prints out an array to the screen, two arguments: an array and its size
void printArray(int array[], int size){
    
    // loop through each element in the array
    for (int i = 0; i < size; i++){
        
        // print out the array element to the screen
        printf("%d ", array[i]);
    }
    
    // print a new line character for readability
    printf("\n");
}

// function that performs an insertion sort algorithm on an array; takes two arguments: an array and its size
void insertionSort(int array[], int size){
    
    // start looping through each element in the array starting with the second element
    for (int element = 1; element < size; element++){
        
        // current_value is the value of the current element
        int current_value = array[element];
        
        // prev_element is the previous element
        int prev_element = element - 1;
        
        // while the current value is less than the value of the previous element AND previous element number is greater than or equal to zero
        while (current_value < array[prev_element] && prev_element >= 0){  // For descending order, change current_value<array[prev_element] to current_value>array[prev_element]
            
            // set the current element value to the value of the previous element
            array[prev_element + 1] = array[prev_element];
            
            // decrement previous element by 1
            --prev_element;
        }
        
        // since previous element was decremented, add 1 to make the previous element 1 behind the current element, then set it to current_value
        array[prev_element + 1] = current_value;
    }
}

// main function
int main(void){
    
    // initialize data array
    int data[] = {500, 1, 50, 23, 76};
    
    // calculate size of array
    int size = sizeof(data) / sizeof(data[0]);
    
    // print out array before sorting
    printf("Array before sorting:\n");
    printArray(data, size);

    // perform insertion sort
    insertionSort(data, size);
    
    // print out array after sorting
    printf("\nSorted array in ascending order:\n");
    printArray(data, size);

    // exit program
    return 0;
}