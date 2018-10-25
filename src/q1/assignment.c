#include <stdio.h>

int main(int arg, char* argc[]) {
	printf("Hello assignment1.\n");

	//my code
	int a;
	int* b;
	long c;
	double* d;
	char** e;

	printf("Int size: %d\n", sizeof(a));
	printf("Int* size: %d\n", sizeof(b));
	printf("Long size: %li\n", sizeof(c));
	printf("Double* size: %ld\n", sizeof(d));
	printf("Char** size: %d\n", sizeof(e));

	return 0;
}
