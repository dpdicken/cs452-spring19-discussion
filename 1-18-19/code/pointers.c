#include "pointers.h"

void *getElement(TwoDArray *array, int row, int col) {
	void *buffer = malloc(array->elementSize);
	void *addr = ((char *)(array->data)) + (array->width * row * array->elementSize) + (col * array->elementSize);
	memcpy(buffer, addr, array->elementSize);
	return buffer;
} 

void setElement(TwoDArray *array, int row, int col, void *data) {
	void *addr = ((char *)(array->data)) + (array->width * (row*array->elementSize)) + (col *array->elementSize);
	memcpy(addr, data, array->elementSize);
}

void printArray(TwoDArray *array) {
	for (int i = 0; i < array->height; i++) {
		for (int j = 0; j < array->width; j++) {
			void *addr = ((char *)(array->data)) + (array->elementSize * (array->width * i)) + (j * array->elementSize);
			printf("%010d ", *((int *)addr));
		}
		printf("\n");
	}
}

TwoDArray *init(int rows, int cols, int dataSize) {
	TwoDArray *new = malloc(sizeof(TwoDArray));
	new->width = cols;
	new->height = rows;
	new->elementSize = dataSize;
	new->data = malloc(rows*cols*dataSize);
	return new;
}
