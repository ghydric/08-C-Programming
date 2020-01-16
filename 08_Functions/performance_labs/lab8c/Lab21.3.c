/*
Author: Mitch Hydrick
Date: 1/16/2020
Title: Performance Lab 21.3: Recursive Main
Synopsis:
    - Can main be called recursively? 
    1. Write a program containing a function   (main).
    2. Include (static) local variable count initialized to 1.
    3. Post-increment and print the value of count each time main is called.
    - What happens when your program runs?
*/

// import necessary libraries
#include <stdio.h>

int main(void){
    // initialize count to 1
    static int count = 1;
    // print out count
    printf("Count is: %d\n", count);
    // base condition (terminating condition)
    if (count == 10){
        return 10;
    } else {  // increment count by 1 then recursively call main() again
        count++;
        return main();
    }
}