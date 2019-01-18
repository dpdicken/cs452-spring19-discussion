#ifndef TWODARRAY_GUARD
#define TWODARRAY_GUARD

typedef struct twodarray {
	int width;
	int height;
	int elementSize;
	void *data;
} TwoDArray;

void *getElement(TwoDArray *array, int row, int col);

void setElement(TwoDArray *array, int row, int col, void *data);

TwoDArray *init(int rows, int cols, int dataSize);

void printArray(TwoDArray *array);

#endif
