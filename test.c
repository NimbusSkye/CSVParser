#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked.h"

int main (void) {
	srand(clock());
	for (int i=0; i<20; i++)    
		findUpdate(i, rand() % 100);
	prettyPrint();
	return 0;
}
