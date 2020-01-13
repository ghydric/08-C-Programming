/*
Author: Mitch Hydrick
Date: 1/13/2020
Title: Performance Lab 15 - "For Loop: Occupandi Temporis"
Synopsis:
Following demo lab 1 for 7.3, you should have identified your past code/programs where a for loop would have been more economical. 
Well NOW is your chance. Create a C file where your previous code is commented out and directly underneath, you implement a for loop.
*/

// Below function used to print out the binary of a decimal number I used previously shows a for loop being implemented

#include <stdio.h>

int get_binary(__INT32_TYPE__ num){
    
    // initialize unsigned integer
    __UINT32_TYPE__ num1;

    for(num1 = 1 << 31; num1 > 0; num1 >>= 1){
        // print 1 or 0 based off the bitwise comparison of num and num1
        fprintf(stdout, "%s", (num & num1)?"1":"0");
    }

    return 0;
}