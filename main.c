// Yufeng Wang 260855204
#include "linked.h"
#include "ssv.h"

#include <stdlib.h>
#include <stdio.h>

int main( ) {

	// Open SSV File
	FILE *read = fopen("bank.ssv","rt");
	
	// Loop that reads each line in the file
	char array[100];
	int *account  = (int*)malloc(sizeof(int));
	float *balance  = (float*)malloc(sizeof(float));
	fgets (array,99,read);
	// Variables for saving information in File
	while (!feof(read)) {
		// Call parse function of ssv.c
		parse(array,account,balance);
		// Call findUpdate function of linked.c
		findUpdate(*account , *balance);
		fgets (array,99,read);
	}
	// Call prettyPrint function of linked.c
	prettyPrint();
	fclose(read);
}

