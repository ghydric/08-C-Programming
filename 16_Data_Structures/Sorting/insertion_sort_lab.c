/*
Author: Mitch Hydrick
Date: 02/11/2020
Title: Performance Lab: Insertion Sort 2
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

// Constants
#define cMax_Ary_Size 15

/* Prototype Declarations */
int insertionSort (int* list, int last);

int main ( void ){
/* Local Declarations */
    int countExch;
    int	ary[cMax_Ary_Size] = {89, 72, 3,  15, 21,\
                               57, 61, 44, 19, 98,\
                                5,  77, 39, 59, 61};

/* Statements */
    printf( "Unsorted array: ");
    for (int i = 0; i < cMax_Ary_Size; i++ )
        printf( "%3d", ary[ i ] );

    countExch = insertionSort ( ary, cMax_Ary_Size - 1);

    printf( "\nSorted array:   " );
    for (int i = 0; i < cMax_Ary_Size; i++)
        printf( "%3d", ary[ i ] );
    printf( "\n" );

    printf("Total exchanges: %d\n", countExch);
    return 0;
}   /* main */

/*  ================== insertionSort ==================== 
    Sort list using Insertion Sort. The list is divided 
    into sorted and unsorted lists. With each pass,  
    first element in unsorted list is inserted into 
    sorted list.
       Pre    list must contain at least one element
              last is index to last element in the list
       Post   list rearranged, exchange counted
       Return count of exchanges
*/
int insertionSort (int* list, int last){

    // counter is incremented every time new assignments take place
    int counter = 0;

    // start looping through each element in the array starting with the second element
    for (int element = 1; element <= last; element++){
        
        // current_value is the value of the current element
        int current_value = list[element];
        counter++;
        
        // prev_element is the previous element
        int prev_element = element - 1;
        
        // while the current value is less than the value of the previous element AND previous element number is greater than or equal to zero
        while (current_value < list[prev_element] && prev_element >= 0){  // For descending order, change current_value<array[prev_element] to current_value>array[prev_element]
            
            // set the current element value to the value of the previous element
            list[prev_element + 1] = list[prev_element];
            counter++;
            
            // decrement previous element by 1
            --prev_element;
        }
        
        // since previous element was decremented, add 1 to make the previous element 1 behind the current element, then set it to current_value
        list[prev_element + 1] = current_value;
        counter++;

    }
    
    return counter;
}   // insertionSort

/*
Results:
Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
Total exchanges: 76
*/