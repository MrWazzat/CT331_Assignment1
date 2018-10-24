#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct{
  void* data;
  struct listElementStruct* next;
  void (*printData)(void*);
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, void (*printData)(void*)){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  e->printData = printData;
  e->data = data;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    current->printData(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, void (*printData)(void*)){
  listElement* newEl = createEl(data, printData);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc0
  free(delete);
}

//Returns the number of elements in a linked list
int length(listElement* list){
  unsigned int length = 0;
  while(list){
    list = list->next;
    length++;
  } 
  return length;
}

//Push a new element onto the head of a list
void push(listElement** list, void* data, void (*printData)(void*)){
  listElement* pushed = createEl(data, printData);
  pushed->next = *list;
  *list = pushed;
}

//Pop an element from the head of a list
listElement* pop(listElement** list){
  listElement* first = *list;
  *list = first->next;
  first->next = NULL;

  return first;
}

//Enqueue a new element onto the head of the list
void enqueue(listElement** list, void* data, void (*printData)(void*)){
  //Same code as push.
  //We're not calling push here in case modifications are to be done.
  listElement* enqueued = createEl(data, printData);
  enqueued->next = *list;
  *list = enqueued;
}

//Dequeue an element from the tail of the list
listElement* dequeue(listElement* list){
  while(list->next->next != NULL){
    list = list->next;
  }
  listElement* dequeued = list->next;
  list->next = NULL;
  return dequeued;
}

//Frees the memory for the list
void destroyList(listElement* list){
  while (list) {
    listElement *current = list;
    list = list->next;
    free(current);
  }
}

//Returns the data from the listElement (Tests purposes)
void* getData(listElement* list){
  return list->data;
}

//Returns the next element of the list (Tests purposes)
listElement* getNext(listElement* list){
  return list->next;
}

