/*
Author: Mitch Hydrick
Date: 02/06/2020
Title: Performance Lab: Singly Linked List
Synopsis:
   - Write a program that creates a linked list of 10 characters, then creates a copy of the list in reverse order.
*/

// import necessary libraries
#include <stdio.h>

// create List_Item Structure
typedef struct List_Item {
    char data;
    struct List_Item *next_ptr;
} Item, *probe;

// create Singly_Linked_List Structure
typedef struct Singly_Linked_List {
    Item item;
    Item *head_ptr;
    Item *tail_ptr;
} Singly, *list, Reversed_Singly, *rev_list;

int main(void){

    char my_letter_list[10] = "helloworld";

    return 0;
}

void Add_Item(Singly *list, Item *new_item){
    if (count(*list) == 0){
        list->item = *new_item;
        list->head_ptr = &new_item;
        list->tail_ptr = &new_item;
    } else {
        /* code */
    }
    
}

void Print_List(Singly list){

}