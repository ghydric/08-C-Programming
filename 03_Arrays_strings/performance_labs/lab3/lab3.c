#include <stdio.h>

int main() {

    static int class_total = 15;

    // initialize array and zeroize all elements
    int student_ages [class_total];
    
    // set first element in array to 60
    student_ages[0] = 60;

    // loop through each index from 1 to 15 and set each index to 20, 30, 40, or 50 based on the logic below
    for (int i = 1; i <= class_total; i++) {

        if (i % 3 == 0) {
            student_ages[i] = 30;
        } else if (i % 4 == 0) {
            student_ages[i] = 40;
        } else if (i % 5 == 0) {
            student_ages[i] = 50;
        } else {
            student_ages[i] = 20;
        }
      
    } // end setting for loop

    // loop through each index from 0 to 14 and print out the value of the index
    for (int x = 0; x < class_total; x++) {
        
        printf("\nStudent %d is %d years old\n", x + 1, student_ages[x]);

    } // end printing for loop

    return 0;
}