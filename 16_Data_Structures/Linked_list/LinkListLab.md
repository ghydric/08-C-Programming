## Complete the Linked List program

```c

#include<stdio.h> 
#include<stdlib.h> 
  
/* A linked list node */
struct Node 
{ 
  int data; 
  struct Node *next; 
}; 
  
  
/* Prints a linked list in reverse manner */
void Part1(struct Node* head) 
{ 
  if(head == NULL) 
    return; 
  
  Part1(head->next); 
  printf("%d  ", head->data); 
} 
  
/* prints alternate nodes of a Linked List, first  
  from head to end, and then from end to head. */
void Part2(struct Node* start) 
{ 
  if(start == NULL) 
    return; 
  printf("%d  ", start->data);  
  
  if(start->next != NULL ) 
    Part2(start->next->next); 
  printf("%d  ", start->data); 
} 
  
/* UTILITY FUNCTIONS TO TEST Part1() and Part2() */
/* Given a reference (pointer to pointer) to the head 
  of a list and an int, push a new node on the front 
  of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
  /* allocate node */
  struct Node* new_node = 
          (struct Node*) malloc(sizeof(struct Node)); 
   
  /* put in the data  */
  new_node->data  = new_data; 
   
  /* link the old list off the new node */
  new_node->next = (*head_ref); 
   
  /* move the head to point to the new node */
  (*head_ref)    = new_node; 
} 
   
/* Driver program to test above functions */
int main() 
{ 
  /* Start with the empty list */
  struct Node* head = NULL; 
  
  /* Using push() to construct below list 
    1->2->3->4->5  */
  push(&head, 5); 
  push(&head, 4); 
  push(&head, 3); 
  push(&head, 2); 
  push(&head, 1);    
   
  printf("Output of Part1() for list 1->2->3->4->5 \n"); 
  Part1(head); 
  
  printf("\nOutput of Part2() for list 1->2->3->4->5 \n");  
  Part2(head); 
          
  getchar(); 
  return 0; 
} 
```


