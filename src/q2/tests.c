#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");

  //MY CODE
  //Test length
  int len = length(l2);
  printf("The number of elements in the list: %d", len);
  printf("\n\n");

  //Test push
  listElement* l3 = createEl("push element 1", 30);
  push(&l3, "push element 2", 30);
  printf("Item pushed into linked list: ");
  traverse(l3);
  printf("\n");

  //Test pop
  printf("Item popped from the linked list: ");
  pop(&l3);
  traverse(l3);
  printf("\n");

  //Test enqueue
  listElement* l4 = createEl("enqueue element 1", 30);
  enqueue(&l4, "enqueue element 2", 30);
  printf("Item enqueued into linked list: ");
  traverse(l4);
  printf("\n");

  //Test dequeue
  printf("Item dequeued from the linked list: ");
  dequeue(&l4);
  traverse(l4);
  printf("\n");


  printf("\nTests complete.\n");
}
