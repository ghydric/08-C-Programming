/*
Author: Mitch Hydrick
Date: 1/24/2020
Title: Performance Lab: Mighty Morphin
Synopsis:
    1. Save the lyrics for the Mighty Morphin' Power Rangers theme song into a text file.
    2. Write a C program to:
        - Open the file in read-only mode
        - Read it char-by-char
        - Print each char as it is read
        - Close the file at the end
*/

// import necessary libraries
#include <stdio.h>

int main(void)
{
    char filename[26] = "mighty_morphin_lyrics.txt";
    FILE * myFile_ptr = fopen(filename, "r");// Opens a read-only file
    char readFromFile = 0; // Store char-by-char input from myFile_ptr
    if (myFile_ptr != NULL) 	// Verify fopen() succeeded… 
    {
        while (readFromFile != EOF) // Continue reading until the end of file
        {
            readFromFile = getc(myFile_ptr); 	// Read one character
            putc(readFromFile, stdout); 		// Print that character
        }
        fclose(myFile_ptr); // Always fclose anything you fopen
    }
    else 			// …Otherwise, fopen() failed
    {
        puts("Error Opening File!"); 	// Tell the user and…
        return -1;			// …Return an error value
    }
    return 0;
}
