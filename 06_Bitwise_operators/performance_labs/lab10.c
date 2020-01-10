/*
Author: Mitch Hydrick
Date: 1/10/2020
Title: Lab 10 Bitwise Shift Right
Synopsis:
    1. Input a uint32_t userInput from stdin utilizing fscanf()
    2. Initialize another uint32_t bitChecker to 0x01
    3. Use a Bitwise Shift Left on bitChecker to ensure only the left most bit is turned on
    4. Print the binary representation of userInput to stdout using only the following:
        i. fprintf()
       ii. Bitwise Shift Right >>
      iii. Bitwise AND &
       iv. Relational Operator (e.g., >)
*/

#include <stdio.h>

int get_binary(__UINT32_TYPE__ num){
    
    // initialize binary string
    char bit_string = "";

    while (num > 0){
        int bit = num % 2;
        int quotient = num / 2;
        
        if (sizeof(bit_string == 0)){
            bit_string += bit;
        } else {
            bit_string >> 1;
            bit_string += bit;
        }
        num = quotient;
    }

    return 0;
}

// start main function
int main(void){

    // initialize unsigned integers
    __UINT32_TYPE__ num1;
    __UINT32_TYPE__ bit_checker = 0x01;

    // prompt and obtain the unsigned integer from user
    fprintf(stdout, "Enter an unsigned integer: \n");
    fscanf(stdin, "%ui", &num1);
    char num_binary = get_binary(num1);
    fprintf(stdout, "You entered: %s", num_binary);


    // exit program
    return 0;

}