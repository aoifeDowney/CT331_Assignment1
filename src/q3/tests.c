#include <stdio.h>
#include "genericLinkedList.h"
#include "tests.h"

//Int data type
void printInt(void* data) {
	printf("%d\n", *(int*)data);
}

//Double data type
void printDouble(void* data) {
	printf("%f\n", *(double*)data);
}

//Char data type
void printChar(void* data) {
	printf("%c\n", *(char*)data);
}

//String data type
void printString(void* data) {
	printf("%s\n", data);
}

void runTests() {

	printf("Tests running...\n");
	
	//Test for passing in an int
	int testInt = 4;
	printf("Test for passing in an int: ");
	genericlistElement* l1 = createEl(&testInt, 30, &printInt);
	traverse(l1);
	printf("\n");

	//Test for passing in a double
	double testDouble = 5.5;
	printf("Test for passing in a double: ");
	genericlistElement* l2 = createEl(&testDouble, 30, &printDouble);
	traverse(l2);
	printf("\n");

	//Test for passing in a char
	char testChar = 'a';
	printf("Test for passing in a char: ");
	genericlistElement* l3 = createEl(&testChar, 30, &printChar);
	traverse(l3);
	printf("\n");

	//Test for passing in a string
	char testString[] = "aoife";
	printf("Test for passing in a string: ");
	genericlistElement* l4 = createEl(&testString, 30, &printString);
	traverse(l4);
	printf("\n");

	printf("\nTests complete.\n");
}