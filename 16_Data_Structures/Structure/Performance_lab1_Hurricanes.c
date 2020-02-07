/*
Author: Mitch Hydrick
Date: 02/07/2020
Title: Performance Lab: Hurricanes
Synopsis:
    - Write a program to read the information in storms2.txt. Use the preceding structure 
      and print the information for the hurricanes that occurred between 1960 and 1969. 
    - Use an output format similar to the following:
        Strongest Hurricanes between 1960 and 1969
        Name  Year  Category
*/

// import necessary libraries
#include <stdio.h>

// define MACRO for filename to retrieve data from
#define FILENAME "storms2.txt"

// Define structure to represent a hurricane
struct hurricane
{
    char name[10];
    int year, category;
};

int main(void){

    // Define and initialize variables
    struct hurricane h1;
    FILE* storms;

    // Print out the Table Name and Headers
    printf("\nStrongest Hurricanes between 1960 and 1969:\n");
    printf("\nName\t\tYear\t\tCategory\n");
    printf("----\t\t----\t\t--------\n");
    
    // Read and process information from file
    storms = fopen (FILENAME, "r");
    if (storms == NULL) {
      printf("Error opening file\n");
   } else {
        while (fscanf(storms, "%s %d %d", h1.name, &h1.year, &h1.category) == 3){
            if (h1.year >= 1960 && h1.year <= 1969){
                printf("%s\t\t%d\t\t   %d\n", h1.name, h1.year, h1.category);
            }
        }
        
        // close the file
        fclose(storms);
   }

   /*  Exit program.  */
   return 0;
}
