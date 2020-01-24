/*
Author: Mitch Hydrick
Date: 1/24/2020
Title: Performance Lab: Content Copy Char-By-Char
Synopsis:
    1. Open an existing file in read mode.
    2. Open a new file in write mode.
    3. Copy the existing file into the new file char-by-char.
    4. Close the existing file.
    5. Close and open the new file in read mode.
    6. Print the new file char-by-char.
*/

// import necessary libraries
#include <stdio.h>

int main(void)
{
    char read_filename[26] = "mighty_morphin_lyrics.txt";
    char write_filename[30] = "new_mighty_morphin_lyrics.txt";
    
    FILE * read_file_ptr = fopen(read_filename, "r");// Opens a read-only file
    FILE * write_file_ptr = fopen(write_filename, "w");// Opens a file for writing
    
    char readFromFile = 0; // Store char-by-char input from myFile_ptr
    if (read_file_ptr != NULL) 	// Verify fopen() succeeded… 
    {
        while (readFromFile != EOF) // Continue reading until the end of file
        {
            readFromFile = getc(read_file_ptr); 	// Read one character
            putc(readFromFile, write_file_ptr); 		// Write that character to new file
        }
        // close both file pointers
        fclose(read_file_ptr);
        fclose(write_file_ptr);
        
        // reset readFromFile
        readFromFile = 0;
        
        // open the newly written file in read mode
        read_file_ptr = fopen(write_filename, "r");
        while (readFromFile != EOF) // Continue reading until the end of file
        {
            readFromFile = getc(read_file_ptr); 	// Read one character
            putc(readFromFile, stdout); 		// Print out that character to screen
        }
        fclose(read_file_ptr); // close the file
    }

    else 			// …Otherwise, fopen() failed
    {
        puts("Error Opening File!"); 	// Tell the user and…
        return -1;			// …Return an error value
    }

    return 0;
}
