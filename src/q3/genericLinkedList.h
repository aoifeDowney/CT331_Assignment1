#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

//typedef struct genericLinkedListElementStruct genericlistElement;
//My Function Pointer
typedef void(*printDataType)(void* data);

typedef struct genericLinkedListElementStruct {
	void* data;
	size_t size;
	struct genericLinkedListElementStruct* next;
	printDataType printData;
} genericlistElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericlistElement* createEl(void* data, size_t size, printDataType);

//Prints out each element in the list
void traverse(genericlistElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
genericlistElement* insertAfter(genericlistElement* after, void* data, size_t size, printDataType);

//Delete the element after the given el
void deleteAfter(genericlistElement* after);

//MY CODE

//Returns the number of elements in a linked list
int length(genericlistElement* length);

/*
Push a new element onto the head of the list
Update the list referencing using side effects
*/
void push(genericlistElement** elementList, void* data, size_t size, printDataType);

/*
Pop an element from the head of the list
Update the list reference using side effects
*/
genericlistElement* pop(genericlistElement** elementList);

//Enqueue a new element onto the head of the list
void enqueue(genericlistElement** elementList, void* data, size_t size, printDataType);

//Dequeue an element from the tail of the list
genericlistElement* dequeue(genericlistElement* elementList);

#endif
