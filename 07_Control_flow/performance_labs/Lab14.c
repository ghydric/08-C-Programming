/*
Author: Mitch Hydrick
Date: 1/13/2020
Title: Performance Lab 14 - "Switch Statement"
Synopsis:
    1. Write a program that will evaluate a simple math formula.
    2. Input the formula with two integers separated by an arithmetic operator from one line.
        - Example: 1 + 1, (-8) - 3, 2 * (-7), (-15) / (-4)
    3. Use a switch statement to print the correct value using the operators as cases.
    4. Set the default condition to an error.
    5. Ensure any division provides a double answer with a precision of two decimal places.
*/

#include <stdio.h>

int main(void){

    // declare 2 numbers as doubles and a char operator
    double num1;
    double num2;
    char operator;

    // prompt user for expression to evaluate
    printf("Enter an expression (ie: 5 * 8): ");
    scanf("%lf %1c %lf", &num1, &operator, &num2);

    switch (operator){
        case '+':
            printf("%lf %c %lf = %lf", num1, operator, num2, num1 + num2);
            break;
        case '-':
            printf("%lf %c %lf = %lf", num1, operator, num2, num1 - num2);
            break;
        case '*':
            printf("%lf %c %lf = %lf", num1, operator, num2, num1 * num2);
            break;
        case '/':
            printf("%lf %c %lf = %0.2lf", num1, operator, num2, num1 / num2);
            break;
        //case '%':
            //printf("%lf %c %lf = %lf", num1, operator, num2, num1 % num2);
            //break;
        default:
            printf("Sumthin bad just happened");
            break;
    }

    return 0;
}
