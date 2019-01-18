#include <assert.h>
#include "pointers.h"

int main() {

	// Initialize array with elements of size 4 (ints)
	TwoDArray *array = init(5, 10, 4);
	
	int x = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			setElement(array, i, j, &x); 
		}
	}

	printArray(array);
	printf("-------------------------------------------------------\n");

	x = 1;
	setElement(array, 2, 3, &x); 
	
	printArray(array);
	
	// Updated value correctly
	assert(*((int *)(getElement(array, 2, 3))) == 1);

	// Other elements unaffected
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 2 && j == 3) continue;
			assert(*((int *)(getElement(array, i, j))) == 0);
		}
	}

}
