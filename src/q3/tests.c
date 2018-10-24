#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "tests.h"
#include "genericLinkedList.h"

/****

This test file is not as test intensive as for the question 2 because the algorithms
are the same.

MEMCHECK DONE WITH VALGRIND (NO LEAKS POSSIBLE)

****/
void printInt(void* value){
  printf("%d\n", *(int *)value);
}

void printFloat(void* value){
  printf("%f\n", *(float *)value);
}

void printStr(void* value){
  printf("%s\n", (char*)value);
}

void runTests(){
  printf("Tests running...\n");

  int value0 = 0;
  char* value1 = "Value 2";
  float value2 = 2.19834;
  

  listElement* el = createEl((void *) &value0 , printInt);
  traverse(el);

  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(el, (void *)value1 , printStr);
  insertAfter(l2, (void *)&value2, printFloat);
  traverse(el);
  printf("\n");

  // Test delete after
  deleteAfter(el);
  traverse(el);
  printf("\n");

  destroyList(el);

  printf("\nAll tests complete.\n");


}