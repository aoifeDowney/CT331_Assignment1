#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericlistElement* createEl(void* data, size_t size, printDataType printData) {
	genericlistElement* e = malloc(sizeof(genericlistElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	char* dataPointer = malloc(sizeof(char)*size);
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	//strcpy(dataPointer, data);
	memmove(dataPointer, data, size);

	e->data = dataPointer;
	e->size = size;
	e->printData = printData;
	e->next = NULL;
	return e;
}

//Prints out each element in the list
void traverse(genericlistElement* start) {
	genericlistElement* current = start;
	while (current != NULL) {
		//printf("%s\n", current->data);
		//current = current->next;

		current->printData(current->data); //printing the data, no matter what type it is
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
genericlistElement* insertAfter(genericlistElement* el, void* data, size_t size, printDataType printData) {
	genericlistElement* newEl = createEl(data, size, printData);
	genericlistElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(genericlistElement* after) {
	genericlistElement* delete = after->next;
	genericlistElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}
	//MY CODE

	//returns the number of elements in a linked list
int length(genericlistElement* list) {
	int count = 0;
	genericlistElement* current = list; //initialzing the current element

	while (current != NULL) {
		count++; //counting through the number of elements in the linked list
		current = current->next;
	}
	return count;

}

	/*Push a new element onto the head of the list
	Update the list referencing using side effects
	*/
	void push(genericlistElement** el, void* data, size_t size, printDataType printData) {
		genericlistElement* newHead = createEl(data, size, printData);
		if (newHead == NULL) {
			exit(0);
		}
		newHead->next = *el;
		*el = newHead; //placing the element at the head of the list
	}

	/*
	Pop an element from the head of the list
	Update the list reference using side effects
	*/
	genericlistElement* pop(genericlistElement** el) {
		genericlistElement* head = *el; //head is the element which I am popping from the linked list
		*el = head->next;
		head->next = NULL;

		return head;
	}

	//Enqueue a new element onto the head of the list
	void enqueue(genericlistElement** el, void* data, size_t size, printDataType printData) {
		genericlistElement* newHead = createEl(data, size, printData);
		if (newHead == NULL) {
			exit(0);
		}
		newHead->next = *el;
		*el = newHead; //placing the element at the head of the list
	}

	//Dequeue an element from the tail of the list
	genericlistElement* dequeue(genericlistElement* el) {
		genericlistElement* currElement = el;
		genericlistElement* prevElement;

		//While there are elements in the queue
		while((currElement->next)->next != NULL){
			currElement = currElement->next;
		}
		genericlistElement* temp = currElement->next;
		currElement->next = NULL;
		return temp; //Returning the value which as just been removed from the queue
	}

