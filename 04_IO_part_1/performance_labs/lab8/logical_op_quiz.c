/*
Title: Logical Operators Quiz
*/

#include <stdio.h>

int main(void){

    int x = 99;
    int y = 0;

    //////// WRITE EACH RESULT ////////
    printf("x && y = %d\n", x && y);
    printf("y || x = %d\n", y || x);
    printf("!y = %d\n", !y);
    printf("y && 0 = %d\n", y && 0);
    printf("x || 42 = %d\n", x || 42);
    printf("!x = %d\n", !x);
    printf("x && x = %d\n", x && x);
    printf("y || y = %d\n", y || y);
    printf("!1 = %d\n", !1);
    printf("1 && 1 = %d\n", 1 && 1);
    printf("(0 && 1) || (2 && 3) = %d\n", (0 && 1) || (2 && 3));        // Bonus

    return 0;
}