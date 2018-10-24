#include <stdio.h>
#include <stddef.h>

int main(int arg, char* argc[]){

	int a;
	int* b;
	long c;
	double* d;
	char** e;

	printf("Size of an int : %lu bytes. \n", sizeof(a));
	printf("Size of an int* : %lu bytes. \n", sizeof(b));
	printf("Size of a long : %lu bytes. \n", sizeof(c));
	printf("Size of a double* : %lu bytes. \n", sizeof(d));
	printf("Size of a char** : %lu bytes. \n", sizeof(e));

	//---- Example code ---- //
	/*

  	printf("Hello assignment1.\n");

  	*/

  	return 0;
}
