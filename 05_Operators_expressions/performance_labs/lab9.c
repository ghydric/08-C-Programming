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
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;
    
    // get leg a and b from user input
    printf("Enter the size of leg a: \n");
    scanf("%05f", &a);
    flush_buffer();
    printf("Enter the size of leg b: \n");
    scanf("%05f", &b);
    flush_buffer();

    if (a < b){
         // calculate leg c (hypotenuse) using Pythagorean Theorem (a^2 + b^2 = c^2)
        c = sqrt((a*a) + (b*b));
    }
   


    return 0;
}