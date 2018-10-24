#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "tests.h"
#include "linkedList.h"

/****

NO MEMORY LEAKS (MEMCHECKED WITH VALGRIND)

****/ 

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String. (1)", 30);
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


  printf("\n------------- Student tests -------------\n");
  //Creating the base list
  listElement* list = createEl("Element 1", 30);
  insertAfter(list, "Element 2", 30);
  assert(strcmp(getData(list), "Element 1") == 0);
  assert(strcmp(getData(getNext(list)), "Element 2") == 0);

  //Tests Stack

  push(&list, "Pushed Element", 30);
  //The first Element is "Pushed Element"
  assert(strcmp(getData(list), "Pushed Element") == 0);

  listElement* poped= pop(&list);
  assert(strcmp(getData(poped), "Pushed Element") == 0);
  assert(strcmp(getData(list), "Element 1") == 0);
  assert(strcmp(getData(getNext(list)), "Element 2") == 0);

  printf("\nStack tests complete.\n");

  //Queue tests
  enqueue(&list,"Enqueued Element",30);
  //The first element is "Enqueued Element"
  assert(strcmp(getData(list), "Enqueued Element") == 0);


  listElement* dequeued = dequeue(list);
  assert(strcmp(getData(dequeued), "Element 2") == 0);
  assert(strcmp(getData(list), "Enqueued Element") == 0);
  assert(strcmp(getData(getNext(list)), "Element 1") == 0);

  printf("\nQueue tests complete.\n");

  destroyList(list);
  destroyList(poped);
  destroyList(dequeued);
  destroyList(l);

  printf("\nAll tests complete.\n");


}
