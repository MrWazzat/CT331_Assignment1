#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST


typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, void (*printData)(void*));

//Delete all the elements of the list and frees the memory
void destroyList(listElement* list);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, void (*printData)(void*));

//Delete the element after the given el
void deleteAfter(listElement* after);

//Returns the number of elements in a linked list
int length(listElement* list);

//Push a new element onto the head of a list
void push(listElement ** list, void* data, void (*printData)(void*));

//Pop an element from the head of a list
listElement* pop(listElement** list);

//Enqueue a new element onto the head of the list
void enqueue(listElement** list, void* data, void (*printData)(void*));

//Dequeue an element from the tail of the list
listElement* dequeue(listElement* list);

//Returns the data from the listElement (Tests purposes)
void* getData(listElement* list);

//Returns the next element of the list (Tests purposes)
listElement* getNext(listElement* list);

#endif
