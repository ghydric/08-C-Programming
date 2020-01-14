/*
Author: Mitch Hydrick
Date: 1/14/2020
Title: Performance Lab 18 - "Continue"
Synopsis:
    1. Input an unsigned integer "x".
    2. Print the first 10 to 20 positive integers that x is divisible by utilizing the mod operator (not the most efficient).
    3. Repeat this process.
    4. Immediately stop this process when the user inputs an integer above 999.
    5. Ignore any "divide by 0" errors using continue.
*/

// import necessary libraries
#include <stdio.h>

// program gets the first 10 divisors of a number less than 999 and loops until a number greater than 999 is entered
int main(void){

    // initialize unsigned int for user input, an int counter for finding divisors, and an int iterations counter 
    unsigned int x = 0;
    int counter = 0;
    int iterations = 1;

    // loop to get number from user and then
    while (x <= 999){
        // flush input buffer
        fflush(stdin);

        // reset iterations and counter
        counter = 0;
        iterations = 1;
        
        // get a number from the user
        printf("\nEnter a number greater than 0 and less than 999: ");
        fscanf(stdin, "%u", &x);
        
        // if the number entered is less than or equal to zero, print error and start loop over
        if (x <= 0){
            printf("You entered an invalid number\n");
            continue;
        } else if (x > 999){  // if the number entered is greater than 999, print error and exit program
            printf("Too high a number, exiting.");
            break;
        } else {  // if the number is in the correct range
            printf("%u is divisible by the following numbers:\n", x);
            
            // loop until iterations is greater than 10 or counter has reached the halfway point of the number entered
            while (iterations <= 10 && counter <= x / 2){
                // increment counter by 1
                counter++;
                // if counter is equal to the number entered, stop looping for divisors
                if (counter == x){
                    break;
                }
                // if number entered divided by the counter leaves no remainder, print out the iteration followed by the counter
                if (x % counter == 0){
                    printf("%d: %d\n", iterations, counter);
                    // increment iterations by 1
                    iterations++;
                }
            // if counter is equal to 1, print out "nothing" since counter never incremented during the finding divisors loop
            } if (counter == 1){
                printf("Nothing\n");
            }
        }

    }

    // exit program
    return 0;
}