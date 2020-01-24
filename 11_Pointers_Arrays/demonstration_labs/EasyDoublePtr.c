/*Create a program to use pointer to pointer
Code a C program to exhibit the use of pointer to a pointer.

	Demonstrate use of pointer to a pointer
 */

#include <stdio.h>

void print_vars(int num1, int * num1_ptr, int ** dbl_num1_ptr);

int main()
{
    // Integer variable
    int num = 0;
    // Pointer to integer
    int * num_ptr = &num;
    // Pointer to integer pointer
    int ** dbl_num_ptr = &num_ptr;
    /* Change the value of num directly */
    num = 10;
    print_vars(num, num_ptr, dbl_num_ptr);


    /* Assigns 100 using pointer to integer */
    * num_ptr = 100;
    print_vars(num, num_ptr, dbl_num_ptr);

    /* Assigns 1000 using pointer to integer pointer */
    ** dbl_num_ptr = 1000;
    print_vars(num, num_ptr, dbl_num_ptr);

    return 0;
}

// function that prints out all of the values of the integer variables/pointers
void print_vars(int num1, int * num1_ptr, int ** dbl_num1_ptr){
    printf("Value of num = %d\n", num1);
    printf("Value pointed by ptr = %d\n", * num1_ptr);
    printf("Value pointed by dPtr = %d\n\n", ** dbl_num1_ptr);
}
/*
 Example Output -

Value of num   = 10
Value pointed by ptr  = 10
Value pointed by dPtr = 10

Value of num   = 100
Value pointed by ptr  = 100
Value pointed by dPtr = 100

Value of num   = 1000
Value pointed by ptr  = 1000
Value pointed by dPtr = 1000
*/