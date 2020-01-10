#define int_size 8
#include <stdio.h>

//int int_size = 32;
char bit_string[int_size];

int get_binary(__UINT8_TYPE__ num, int size){

    if (size != 0){
        int bit = num % 2;
        int quotient = num / 2;
        bit_string[size - 1] = (char)bit;
        num = quotient;
        return 0;
    } else {
        return get_binary(num, size - 1);
    }
}

// start main function
int main(void){

    // initialize unsigned integers
    __UINT32_TYPE__ num1;
    //__UINT32_TYPE__ bit_checker = 0x01;

    // prompt and obtain the unsigned integer from user
    fprintf(stdout, "Enter an unsigned integer: \n");
    fscanf(stdin, "%u", &num1);
    get_binary(num1, int_size);
    fprintf(stdout, "%u in binary is: %s", num1, bit_string);


    // exit program
    return 0;

}