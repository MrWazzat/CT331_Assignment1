#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
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
  //need to free the memory because we used malloc
  free(delete->data);
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
void push(listElement** list, char* data, size_t size){
  listElement* pushed = createEl(data, size);
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
void enqueue(listElement** list, char* data, size_t size){
  //Same code as push.
  //We're not calling push here in case modifications are to be done.
  listElement* enqueued = createEl(data, size);
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
    free(current->data);
    free(current);
  }
}

//Returns the data from the listElement (Tests purposes)
char* getData(listElement* list){
  return list->data;
}

//Returns the next element of the list (Tests purposes)
listElement* getNext(listElement* list){
  return list->next;
}

