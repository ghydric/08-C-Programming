/*
Author: Mitch Hydrick
Date: 1/14/2020
Title: Performance Lab 19 - "Nested Control Flow"
Synopsis:
    1. Print all the even or odd numbers from 0 to 100.
    2. Prompt the user for input to indicate odds or evens.
    3. Loop from 0 to 100 and print all indicated numbers.
    4. Use and IF statement to check if even or odd.
    5. BONUS: Ask the user to continue with a DO-WHILE loop
    * write a version with the counting loop written as a FOR loop, and a WHILE loop version.
*/

// import necessary libraries
#include <stdio.h>

// initialize choice for user input
int choice = 0;
// initialize again as true
int again = 1;
// initialize counting max value
int max = 100;

// function to show the menu to the user
void show_menu(void){
    printf("\nChoose one of the following options:\n\n");
    printf("\t(1) Show odd numbers from 0 to 100\n");
    printf("\t(2) Show even numbers from 0 to 100\n");
    printf("\t(3) Exit program\n\n");
    printf("----------------------------------------------------\n");
    printf("Option #: ");
}

void print_nums(char num_type[]){
    if (num_type == "even"){
        for(int i = 0; i <= max; i += 2){
            if (i == 100){
                printf("%d", i);
                break;
            }
            printf("%d, ", i);
        }
    } else if (num_type == "odd"){
        for(int i = 1; i <= max; i += 2){
            if (i == 99){
                printf("%d", i);
                break;
            }
            printf("%d, ", i);
        }
    } else {
        printf("Something messed up!\n");
    }
}

// program shows a menu
int main(void){
    do {
        //reset choice
        choice = 0;

        while (choice != 1 && choice != 2 && choice != 3){
            // flush input buffer
            fflush(stdin);
            printf("\n\n\n");
            // show the menu to the user
            show_menu();
            // take in the choice from user input
            scanf("%1d", &choice);
        }

        switch (choice)
        {
        case 1:
            print_nums("odd");
            break;
        case 2:
            print_nums("even");
            break;
        case 3:
            printf("Exiting now. Bye bye.");
            again = 0;
            break;
        default:
            break;
        }
        

    } while (again == 1);
    

    return 0;
}