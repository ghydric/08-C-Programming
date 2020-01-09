// Arithmetic Operators Quiz

#include <stdio.h>

int x = 7;
int y = 4;
float z = 0;

int reset_variables(void){
    x = 7;
    y = 4;
    z = 0;
}

int main(void) {
    
    char * exp_array[] = {"x * y", "x / y", "x % y", "y + x", "y - x", "-y", "++x", "y++", "x--", "--y", "1 + 2 * (3 + y) + 5)"};
    //////// WRITE EACH RESULT ////////
    for (int i = 0; i < 11; i++) {
        printf("x = %d, y = %d, z = %f\n", x, y, z);
        printf("%s = %d\n", exp_array[i], (int)exp_array[i]);
        reset_variables();
    }
    
/*
    printf("x * y = %d\n", x * y);  // returns 28
    reset_variables();
    printf("z = x / y, z = %d\n", x / y);  // returns 1
    reset_variables();
    printf("x % y = %d\n", x % y);  // returns 3
    reset_variables();
    printf("y + x = %d\n", y + x);  // returns 11
    reset_variables();
    printf("y - x = %d\n", y - x);  // returns -3
    reset_variables();
    printf("-y = %d\n", -y);  // returns -4
    reset_variables();
    printf("++x = %d\n", ++x);  // returns 8
    reset_variables();
    printf("y++ = %d\n", y++);  // returns 4
    reset_variables();
    printf("x-- = %d\n", x--);  // returns 6
    reset_variables();
    printf("--y = %d\n", --y);  // returns 3
    reset_variables();
    printf("1 + 2 * (3 + y) + 5 = %d", 1 + 2 * (3 + y) + 5);  // returns 20
*/
    return 0;
}