/* C implementation QuickSort */
#include<stdio.h> 

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

/* This function takes last element value as pivot, places 
the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot, then returns the index of the pivot */
int partition (int arr[], int start_index, int end_index) 
{ 
    // get the value of the last element in the array and set that value as the pivot
    int pivot_value = arr[end_index];

    // start probe at beginning index, loop until probe reaches second to last index (since the last index is the pivot)
    for (int probe_index = start_index; probe_index <= end_index - 1; probe_index++) 
    { 
        // ff current element (probe) value is smaller than the pivot value
        if (arr[probe_index] < pivot_value) 
        { 
            // swap the probe value with the value of start_index
            swap(&arr[start_index], &arr[probe_index]); 
            
            // increment the start index by 1
            start_index++;
        }
    }
    
    // since start_index is now the correct location for the pivot value, swap the pivot value and the end_index value
    swap(&arr[start_index], &arr[end_index]); 
    
    // return the index of the pivot to the quickSort function
    return start_index; 
} 

// The main function that implements QuickSort 
void quickSort(int arr[], int start_index, int end_index) 
{ 
    if (start_index < end_index) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pivot_index = partition(arr, start_index, end_index); 

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, start_index, pivot_index - 1);
        quickSort(arr, pivot_index + 1, end_index);
    } 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

// Driver program to test above functions 
int main() 
{ 
    int arr[] = {10, 7, 4, 3, 9, 1, 5}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, arr_size - 1); 
    printf("Sorted array: \n"); 
    printArray(arr, arr_size); 
    return 0; 
}