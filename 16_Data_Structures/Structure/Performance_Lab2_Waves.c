/*
Author: Mitch Hydrick
Date: 02/07/2020
Title: Performance Lab: Waves
Synopsis:
    - Write a program that prints out a report giving the Maximum wave height for the tsunamis in "waves2.txt."
      Include the average wave height(in feet) and the location of all tsunamis with a wave height higher than the average.
    - Use an output format similar to the following:
        Summary Information for Tsunamis:
        Maximum Wave height ( in feet): 101.68
        Average Wave height ( in feet): 42.67
        Tsunamis with greater than the average heights:
        Flores_Island
        Okushiri, _Japan
        Eastern_Java
        Papua,_New_Guinea
*/

// import necessary libraries
#include <stdio.h>

// initialize MACRO for waves filename
#define FILENAME "waves2.txt"

// initialize structure for tsunami
typedef struct tsunami
{
    int m, d, y, deaths;  // month, day, year, # of deaths
    double max_height;    // max tsunami wave height
    char location[20];    // location of tsunami
} T;

int main(void){
    
    // declare/initialize variables
    T wave;                                     // instance of tsunami
    FILE* waves;                                // waves variable will hold the file handle for waves2.txt as it is read
    int counter = 0;                            // counter for how many tsunamis are read in to calculate average
    double tallest_height = 0;                  // height of the tallest of all tsunamis read in
    double height_total = 0;                    // total heights of all tsunamis
    double height_average = 0;                  // average height of all tsunamis read in
    char *locs_higher_than_average[10] = {0};   // array that will hold Tsunami locations that have higher than average wave heights
    T wave_list[10] = {0};                      // array that will hold all tsunami instances read in from waves2.txt

    // open file to read in tsunamis
    waves = fopen(FILENAME, "r");
    
    if (waves == NULL){
        printf("Error opening file\n");
    } else {
        
        // print out name of table 
        printf("\nSUMMARY INFORMATION ON TSUNAMIS:\n\n");

        // loop through each line of data in the waves file
        while (fscanf(waves, "%d %d %d %d %lf %s",
        &wave.m, &wave.d, &wave.y, &wave.deaths,
        &wave.max_height, wave.location) == 6){
            
            // add tsunami instance to wave_list array
            wave_list[counter] = wave;

            // increment counter by 1
            counter += 1;

            // add tsunami height to height_total
            height_total += wave.max_height;

            if (wave.max_height > tallest_height){
                tallest_height = wave.max_height;
            }
        }

        // close the file
        fclose(waves);

        // calculate the average height of all the tsunamis read in
        height_average = height_total / counter;

        // print out more data for table
        printf("Maximum wave height is: %.02lf ft.\n", tallest_height);
        printf("Average wave height is: %.02lf ft.\n\n", height_average);
        printf("Locations with tsunamis higher than the average:\n");

        // loop through all tsunamis and print out the locations of the ones that were higher than the average
        for (counter = 0; counter <= 9; counter++){
            if (wave_list[counter].max_height > height_average){
                printf("-> %s\n", wave_list[counter].location);
            }
        }
    }
    
    // exit program
    return 0;
}