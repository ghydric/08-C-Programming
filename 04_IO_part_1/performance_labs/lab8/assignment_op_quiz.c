/*
Title: Assignment Operators Quiz
*/

#include <stdio.h>

// initialize numbers to use with assignment operators
int x = 9;
int y = 3;

// function to reset the variables after each expression
int reset_variables(void){
    x = 9;
    y = 3;
}

int main(void){

    //////// WRITE EACH VALUE OF X ////////
    printf("x *= y = %d\n", x *= y);  // returns 27
    reset_variables();
    printf("x /= y = %d\n", x /= y);  // returns 3
    reset_variables();
    printf("x %= y = %d\n", x %= y);  // returns 0
    reset_variables();
    printf("x += y = %d\n", x += y);  // returns 12
    reset_variables();
    printf("x -= y = %d\n", x -= y);  // returns 6
    reset_variables();
    printf("x *= ++y = %d\n", x *= ++y);  // returns 36
    reset_variables();
    printf("x /= y-- = %d\n", x /= y--);  // returns 3
    reset_variables();
    printf("x %= --x = %d\n", x %= --x);  // returns 0
    reset_variables();
    printf("x += --y = %d\n", x += --y);  // returns 11
    reset_variables();
    printf("x -= y++ = %d\n", x -= y++);  // returns 6
    reset_variables();
    printf("(y %= y) || (x /= x--) = %d\n", (y %= y) || (x /= x--));  // returns 0

    return 0;
}