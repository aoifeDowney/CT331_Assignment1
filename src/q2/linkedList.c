#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct {
	char* data;
	size_t size;
	struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size) {
	listElement* e = malloc(sizeof(listElement));
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
	strcpy(dataPointer, data);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	return e;
}

//Prints out each element in the list
void traverse(listElement* start) {
	listElement* current = start;
	while (current != NULL) {
		printf("%s\n", current->data);
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size) {
	listElement* newEl = createEl(data, size);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}
	//MY CODE

	//returns the number of elements in a linked list
	int length(listElement* list) {
		int count = 0;
		listElement* current = list; //initialzing the current element

		while (current != NULL) {
			count++; //counting through the number of elements in the linked list
			current = current->next;
		}
		return count;

	}

	/*Push a new element onto the head of the list
	Update the list referencing using side effects
	*/
	void push(listElement** elementList, char* data, size_t size) {
		listElement* newHead = createEl(data, size);
		if (newHead == NULL) {
			exit(0);
		}
		newHead->next = *elementList;
		*elementList = newHead; //placing the element at the head of the list
	}

	/*
	Pop an element from the head of the list
	Update the list reference using side effects
	*/
	listElement* pop(listElement** elementList) {
		listElement* head = *elementList; //head is the element which I am popping from the linked list
		*elementList = head->next;
		head->next = NULL;

		return head;
	}

	//Enqueue a new element onto the head of the list
	void enqueue(listElement** elementList, char* data, size_t size) {
		listElement* newHead = createEl(data, size);
		if (newHead == NULL) {
			exit(0);
		}
		newHead->next = *elementList;
		*elementList = newHead; //placing the element at the head of the list
	}

	//Dequeue an element from the tail of the list
	listElement* dequeue(listElement* elementList) {
		listElement* currElement = elementList;
		listElement* prevElement;

		//While there are elements in the queue
		while ((currElement->next)->next != NULL) {
			currElement = currElement->next;
		}
		listElement* temp = currElement->next;
		currElement->next = NULL;
		return temp; //Returning the value which as just been removed from the queue
}



