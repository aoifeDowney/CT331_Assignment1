#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, char* data, size_t size);

//Delete the element after the given el
void deleteAfter(listElement* after);

//MY CODE

//Returns the number of elements in a linked list
int length(listElement* length);

/*
Push a new element onto the head of the list
Update the list referencing using side effects
*/
void push(listElement** elementList, char* data, size_t size);

/*
Pop an element from the head of the list
Update the list reference using side effects
*/
listElement* pop(listElement** elementList);

//Enqueue a new element onto the head of the list
void enqueue(listElement** elementList, char* data, size_t size);

//Dequeue an element from the tail of the list
listElement* dequeue(listElement* elementList);

#endif
