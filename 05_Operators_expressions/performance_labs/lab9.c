/*
Author: Mitch Hydrick
Date: 9 Jan 2020
Title: Performance Lab 9
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

// function to flush the buffer
int flush_buffer() {
    fseek(stdin,0,SEEK_END);
    return 0;
}

// start main function
int main(void){
    
    // initialize triangle leg a, b, and c
    double a, b, c;

    // get leg a and b from user input
    printf("Enter the size of leg a: \n");
    scanf("%lf", &a);
    flush_buffer();
    printf("Enter the size of leg b: \n");
    scanf("%lf", &b);
    flush_buffer();

    if (a > 0 && b > 0){
         // calculate leg c (hypotenuse) using Pythagorean Theorem (a^2 + b^2 = c^2)
        c = sqrt((a*a) + (b*b));
        printf("The length of the hypotenuse is %lf\n", c);
    } else {
        printf("Not a real triangle. Try again.");
    }
   


    return 0;
}