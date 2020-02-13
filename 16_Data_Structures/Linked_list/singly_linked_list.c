/*
Author: Mitch Hydrick
Date: 02/06/2020
Title: Performance Lab: Singly Linked List
Synopsis:
   - Write a program that creates a linked list of 10 characters, then creates a copy of the list in reverse order.
*/

// import necessary libraries
#include <stdio.h>

// define MAXSIZE MACRO
#define MAXSIZE 10

// initialize global variable count for amount of items currently added to the linked list
int count = 0;

// create List_Item Structure
typedef struct List_Item {
    char data;
    struct List_Item* next_ptr;
} Item;

// create Singly_Linked_List Structure
typedef struct Singly_Linked_List {
    Item* item;
    Item* head_ptr;
    Item* tail_ptr;
} Singly;

int Append_Item(Singly* list, char data){
    
    // set new_Item pointer to the address of list
    Item* new_item = list + count;
    
    // if this is the first item in linked list, set the next pointer to null,
    // set data property to passed in character, set list head and tail pointers to the new_item
    if (count == 0){
        new_item->data = data;
        new_item->next_ptr = NULL;
        list->head_ptr = new_item;
        list->tail_ptr = new_item;
        return 0;
    } else if (count == MAXSIZE){
        return -1;
    } else {
        new_item->data = data;
        new_item->next_ptr = ((list + count) - 1);
        list->tail_ptr = new_item;
    }
}

int main(void){

    // initialize added to check if items were successfully added
    int added = 0;

    // allocate memory for the list 
    Singly* my_list = (Singly*)malloc((sizeof(Item) * MAXSIZE));

    // check if list was not allocated properly
    if (!my_list){
        printf("The list did not get allocated correctly. Exiting...\n");
        return -1;
    }

    // initialize character array to be added to linked list and reversed
    char my_letter_list[MAXSIZE] = "helloworld";
    
    // create a character pointer that will loop through the letter list
    char* char_ptr = &my_letter_list;
    
    // loop through the letter list until null character is found
    while (*char_ptr){
        
        // add the item to the linked list using the address of the list
        added = Append_Item(my_list, *char_ptr);

        // check if the item was not successfully added to the linked list
        if (added == -1){
            printf("Item was unable to be added due to list is full. Exiting program.\n");
            break;
        }

        // increment character pointer to point to the next letter in the letter list
        *char_ptr++;

        // increment count by 1
        count++;
    }

    // if added is -1, exit program
    if (added == -1){
        return -1;
    }

    return 0;
}



void Print_List(Singly* list){
    while(list->item){
        printf("%c", list->item->data);
        list->item++;
    }
}