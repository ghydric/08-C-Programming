/*
Author: Mitch Hydrick
Date: 02/10/2020
Title: Performance Lab: Binary Searching
Synopsis:
    - Write a C program that implements a binary search algorithm.
    - Example output:
        Array: 5 10 15 20 25 26 34 56 77

        Please enter the searched key: 26
        The key 26 was found at 5 ( Starting from 0)
*/

// import necessary libraries
#include<stdio.h>
#include<stdlib.h>

// iterative binary search function
int binarySearch(const int *arr, int arr_sz, int key){
	
    // initialize low and high indexes
    int low_index = 0;
	int high_index = arr_sz - 1;
	
    // start search loop
    while(low_index <= high_index){
		
        // find the middle index
        int mid_index = (low_index + high_index) / 2;
        
        if(arr[mid_index] == key){          // check if key, return middle index
			return mid_index;
		}else if (key < arr[mid_index]){    // check if key is less than middle index, set high index to current middle index - 1
			high_index = mid_index - 1;
		}else{                              // else it must have been higher, so set low index to current middle index + 1
			low_index = mid_index + 1;
		}
	}
    // if not found, return -1
	return -1;
}

int main(void){
    
    // declare search key
    int search_key;
    
    // initialize array
	int arr[9] = {5, 10, 15, 20, 25, 26, 34, 56, 77};
    
    // calculate size of array
    int arr_size = (sizeof(arr)/sizeof(arr[0]));
	
    // print out array
    printf("\nArray: ");
    for (int i = 0; i < arr_size; i++){
        if (i == (arr_size - 1)){
            printf("%d\n\n", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }

    // obtain search key from user
    printf("Please enter the search key: ");
    scanf("%d", &search_key);

    // perform binary search
    int indexOf = binarySearch(arr, arr_size, search_key);
	if (indexOf == -1){
        printf("The search key was not found in the array.\n");
    } else {
        printf("The key %d was found at index %d\n", search_key, indexOf);
    }
    
    // exit program
	return 0;
}