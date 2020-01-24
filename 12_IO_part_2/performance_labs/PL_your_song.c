/*
Author: Mitch Hydrick
Date: 1/24/2020
Title: Performance Lab: Your Song
Synopsis:
    1. Save your favorite song into a text file.
    2. Write a C program to:
        - Open the file in read-only mode.
        - Read it line-by-line.
        - Print each line as it is read.
        - Close the file at the end.
*/

// import necessary libraries
#include <stdio.h>

int main(void)
{
    char filename[26] = "mighty_morphin_lyrics.txt";
    FILE * myFile_ptr = fopen(filename, "r"); // Opens a read-only file
    char tempBuff[256] = { 0 };	// Temporary zeroized buffer to store read lines
    char * tempReturnValue = tempBuff; // Holds fgets() return value
    // As long as the file opened successfully
    if (myFile_ptr != NULL){
        while (tempReturnValue) // Continue reading until return value is NULL
        {
            tempReturnValue = fgets(tempBuff, 256, myFile_ptr);
            if (tempReturnValue) 	// If EOF hasn’t been reached…
            {
                puts(tempBuff);	// …print the buffer
            }
        }
        fclose(myFile_ptr); // Always fclose anything you fopen
    } else {
        return -1;
    }
    return 0;
}