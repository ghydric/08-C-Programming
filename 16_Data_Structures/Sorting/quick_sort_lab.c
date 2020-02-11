/*
Author: Mitch Hydrick
Date: 02/11/2020
Title: Performance Lab: Quick Sort 2
Synopsis:
    - Write a C program that implements the quick sort algorithm. 
*/

// import necessary libraries
#include <stdio.h>
#include <stdbool.h>

// Define Constants
#define cMax_Ary_Size 15

// Prototype Declarations
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);
void quickSort(int* data, int left, int right, int* count);
void swap(int* a, int* b);

int main ( void ){
    
    // Local Declarations
    int countExch;
    int	ary[cMax_Ary_Size] = {89, 72, 3,  15, 21, \
                               57, 61, 44, 19, 98, \
                                5,  77, 39, 59, 61};

    // Statements
    printf( "Unsorted array: ");
    for (int i = 0; i < cMax_Ary_Size; i++ )
        printf( "%3d", ary[ i ] );

    countExch = 0;
    quickSort (ary, 0, cMax_Ary_Size, &countExch);

    printf( "\nSorted array:   " );
    for (int i = 0; i < cMax_Ary_Size; i++)
        printf( "%3d", ary[ i ] );
    printf( "\n" );

    printf("Total exchanges: %d\n", countExch);
    return 0;

} // end main function

// A utility function to swap two elements 
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t; 
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high){
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element 

    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high, int* count){ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1, *count); 
        quickSort(arr, pi + 1, high, *count); 
    }
}

/* Function to print an array */
void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

/*
Results:
Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
Total exchanges: 52
*/