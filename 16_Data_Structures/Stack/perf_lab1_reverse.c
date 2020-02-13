/*
Author: Mitch Hydrick
Date: 02/12/2020
Title: Performance Lab: Reverse words using stack operations
Synopsis:
    - Write a C program that inputs a line of text and
      uses a stack to print the line reversed.
*/

// import necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define MACROS
#define MAXSIZE 64  // max size of stack

// initialize global variable count to keep track of the item count on the stack
int count = 0;

// define stackNode structure
typedef struct stackNode {
    char data; // node data
    struct stackNode *next_ptr; // pointer to next node
} StackNode;

// define top node pointer
// struct stackNode** top;
struct stackNode* top = NULL;

// function prototypes
int push(StackNode** top_ptr, char info);
char pop(StackNode** top_ptr);
int is_empty(void);
int is_full(void);
int peek(StackNode** top_ptr);

int main(void){

    // initialize input_str as a zeroized array
    char input_str[MAXSIZE] = {0};

    // obtain input string from user
    printf("Enter a string:\n");
    scanf("%63[^\n]c", input_str);

    printf("String length is: %d\n", strlen(input_str));

    // initialize character pointer to the address of the input_str for looping
    char* char_ptr = &input_str;


/*
    // dynamically allocate memory for top node
    StackNode* top = (StackNode*)malloc(sizeof(StackNode));
    printf("The initialized address of top: %d\n", top);
    // check if it was not allocated properly
    if (!top){
        printf("Could not allocate memory for top.\n");
        return -1;
    }
*/

    // initialize data and next node to NULL character for top
    // **top->data = '\0';
    // **top->next_ptr = '\0';

    // loop through each character in string and push onto the stack
    while (*char_ptr){
        printf("Count before push is: %d\n", count);
        int success = push(&top, *char_ptr);
        printf("success: %d\n", success);
        if (success == -1){ // exit program if memory was not able to be properly allocated
            printf("Memory was not allocated properly, exiting program.\n");
            return -1;
        } else if(success == 1){ // if stack is full, print error and break out of loop so no more items are attempted to be pushed on stack
            printf("Stack is full.\n");
            break;
        } else {
            // increment stack counter by 1 since the push was successful
            count++;
            printf("Count after push is: %d\n", count);
            *char_ptr++;
        }
    }

    // check the top item
    printf("The top item in the stack is: %c\n", peek(&top));

    // pop each item off in the stack displaying the input string reversed
    while (count != 0){
        char character = pop(&top);
        printf("%c", character);
        count--;
    }
} // end of main function

int peek(StackNode** top_ptr) {
   StackNode* curr_top = *top_ptr;
   return curr_top->data;
}

int is_full(void){
   printf("Count inside is_full function: %d\n", count);
   if(count == MAXSIZE)
      return 1;
   else
      return 0;
}

int is_empty(void){
   if(count == 0){
      return 1;
   } else {
      return 0;
   }
}

int push(StackNode** top_ptr, char info){

    // check to see if stack is full first
    //int full = is_full();
    //printf("Full: %d\n", full);
    if (is_full()){
        return 1;
    } else {
        // dynamically allocate memory for new node
        StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
        printf("newnode address: %d\n", new_node);
        // check if memory was not allocated successfully
        if (!new_node){
            return -1;
        }

        // initialize data to info for new node
        new_node->data = info;

        printf("new_node data: %c\n", new_node->data);
        
        if (is_empty()){
            // set the next pointer to point to null
            new_node->next_ptr = '\0';
        } else {
            // set the next pointer to point to the current top node
            new_node->next_ptr = (*top_ptr);
        }

        // update top_ptr to point to this new top node
        (*top_ptr) = new_node;
        printf("new_node next_ptr: %d\n", new_node->next_ptr);
        printf("top_ptr: %d\n", *top_ptr);
    }
    return 0;
}

char pop(StackNode** top_ptr){
    // check if the stack is empty first
    if (is_empty()){
        printf("\nStack is empty.\n");
    } else {

        // save top_ptr address to free later
        StackNode* curr_top = *top_ptr;

        // save the character stored in top_ptr
        char popped = curr_top->data;

        // set top_ptr to point to its next_ptr address
        (*top_ptr) = curr_top->next_ptr;
        
        // free curr_top pointer
        free(curr_top);

        // return the character popped of the stack
        return popped;
    }
}
//*/