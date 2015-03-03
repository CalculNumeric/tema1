#include "matrix.h"
#include <stdlib.h>


/* Constructor - set width and height and allocate memory for the matrix */
BooleanMatrix::BooleanMatrix(int width, int height)
{
	this->width = width;
	this->height = height;

	//allocate enough space for the matrix
	this->integerDownsizedWidth = (width / sizeof(int)+1);
	this->matrix = (int *)malloc(sizeof(int)* height *  this->integerDownsizedWidth);
}

/* Set the integers on the row provided through the index */
void BooleanMatrix::setRow(int index, int values[])
{
	int i;
	// go to the row in question
	int * p = this->getRow(index);

	// overwrite the integers on the row
	for (i = 0; i < this->integerDownsizedWidth; i++)
		p[i] = values[i];
}

/* Set the integer on the row and column specified */
void BooleanMatrix::setRowInt(int row, int index, int value)
{
	int * p = this->getRow(row);
	p[index] = value;
}

/* Set a specific bit */
void BooleanMatrix::setBit(int row, int column, bool value)
{
	int * p = this->getRow(row);
	if (value)
		p[column / sizeof(int)] = p[column / sizeof(int)] | (1 << (column % sizeof(int)));
	else
		p[column / sizeof(int)] = p[column / sizeof(int)] & (!(1 << (column % sizeof(int))));
}	

/* Get the value of a bit */
bool BooleanMatrix::getBit(int row, int column)
{
	int * p = this->getRow(row);
	return (p[column / sizeof(int)] >> (column % sizeof(int))) & 1;
}


/* Return a pointer to the offset in the matrix buffer coresponding to the specific row index */
int * BooleanMatrix::getRow(int index)
{
	return this->matrix + (sizeof(int)* this->integerDownsizedWidth * index);
}