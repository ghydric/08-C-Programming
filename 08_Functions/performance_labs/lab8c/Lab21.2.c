/*
Author: Mitch Hydrick
Date: 1/16/2020
Title: Performance Lab 21.2: Recursive Greatest Common Divisor
Synopsis:
    - The greatest common divisor of integers (x) and (y) is the largest integer that evenly 
      divides both (x) and (y). Write a function (gcd) that returns the greatest common divisor of (x) and (y). 
	- The (gcd) of (x) and (y) is defined recursively as follows: if (y) is equal to 0, then (gcd(x, y)) is (x); 
      otherwise (gcd (x) and (y)) is (gcd (y, x % y)), where % is the remainder operator.
*/

// import necessary libraries
#include <stdio.h>

// gcd function recursively finds the gcd of two integers
int gcd(int x, int y){
    // if y is zero, then x is the gcd, so return x
    if (y == 0){
        return x;
    } else {  // if y is not zero, mod x and y until y does equal zero
        return gcd(y, x % y);
    }
}

// main function
int main(void){
    // declare the two integers
    int x, y;
    
    // get the two integers from the user
    printf("Enter the two numbers to get the GCD of (x y): \n");
    scanf("%d %d", &x, &y);
    
    // print the output
    printf("The GCD of %d and %d is %d", x, y, gcd(x,y));
    return 0;
}