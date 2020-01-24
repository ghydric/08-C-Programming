/*
Author: Mitch Hydrick
Date: 1/24/2020
Title: Performance Lab: Content Copy Line-By-Line
Synopsis:
    1. Open an existing file in read mode.
    2. Open a new file in write mode.
    3. Copy the existing file into the new file line-by-line .
    4. Close the existing file.
    5. Close and open the new file in read mode.
    6. Print the new file line-by-line.
*/

// import necessary libraries
#include <stdio.h>

int main(void)
{
    char read_filename[26] = "mighty_morphin_lyrics.txt";
    char write_filename[31] = "new2_mighty_morphin_lyrics.txt";
    
    FILE * read_file_ptr = fopen(read_filename, "r"); // Open a read-only file
    FILE * write_file_ptr = fopen(write_filename, "w"); // Open a file for writing
    char tempBuff[256] = { 0 };	// Temporary zeroized buffer to store read lines
    char * tempReturnValue = tempBuff; // Holds fgets() return value
    
    // As long as the file opened successfully
    if (read_file_ptr != NULL){
        while (tempReturnValue) // Continue reading until return value is NULL
        {
            tempReturnValue = fgets(tempBuff, 256, read_file_ptr);
            if (tempReturnValue) 	// If EOF hasn’t been reached…
            {
                fputs(tempBuff, write_file_ptr);	// write the buffer to the new file
            }
        }
        // close the open files
        fclose(read_file_ptr);
        fclose(write_file_ptr);

        // reset buffer
        for (int i = 0; i <= 255; i++){
            tempBuff[i] = 0;
        }

        // open the newly written file and read line by line, printing each line to the screen
        read_file_ptr = fopen(write_filename, "r");
        while (tempReturnValue) // Continue reading until return value is NULL
        {
            printf("it works!");
            tempReturnValue = fgets(tempBuff, 256, read_file_ptr);
            if (tempReturnValue) 	// If EOF hasn’t been reached…
            {
                fputs(tempBuff, stdout);	// …print the buffer
            }
        }
        // close the open files
        fclose(read_file_ptr);

    } else {
        return -1;
    }
    return 0;
}