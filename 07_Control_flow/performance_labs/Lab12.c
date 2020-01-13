/*
Author: Mitch Hydrick
Date: 1/13/2020
Title: Performance Lab 12 - "If-Else Statement"
Synopsis:
    1. Initialize a signed int to 0.
    2. Input a number from the user and store it in the signed int.
    3. Determine if the number is negative or positive utilizing a bitwise operator.
    4. Utilizing an IF-ELSE statement:
        - INDICATE if the number is negative.
        - Otherwise, print the original value in binary, and use a bitwise operation to flip one bit to make it negative.
    5. Print the binary
*/

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

// start main function
int main(void){

    // initialize signed int and bitchecker
    __INT32_TYPE__ signed_num = 0;
    __UINT32_TYPE__ bitchecker;

    // prompt and obtain the signed integer from user
    fprintf(stdout, "Enter a number: \n");
    fscanf(stdin, "%d", &signed_num);
    get_binary(signed_num);

    // exit program
    return 0;
}