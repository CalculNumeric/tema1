#include "matrix.h"
#include <string.h>
#include <stdlib.h>


/* Constructor - set width and height and allocate memory for the matrix */
BooleanMatrix::BooleanMatrix(int width, int height)
{
	int i, j;
	this->width = width;
	this->height = height;

	this->integerDownsizedWidth = (width / 32 + 1);
	this->matrix = new int*[height+1];   // + 1 for the requests for rows that exceed the height of the matrix - return last, uncounted row
	for (i = 0; i < height+1; i++)
	{
		this->matrix[i] = new int[this->integerDownsizedWidth];
		for (j = 0; j < this->integerDownsizedWidth; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
}

/* Set the integers on the row provided through the index */
void BooleanMatrix::setRow(int index, int values[])
{
	int i;
	// go to the row in question
	int * p = this->getRow(index);
	// overwrite the integers on the row
	// TO TRY EXCEPT THIS - possible lower size of values
	for (i = 0; i < this->integerDownsizedWidth; i++)
		p[i] = values[i];
}


/* Or a specific row in the matrix with a series of values */
void BooleanMatrix::orRow(int index, int values[])
{
	int i;
	for (i = 0; i < this->integerDownsizedWidth; i++)
	{
		this->matrix[index][i] |= values[i];
	}
}


/* Set the integer on the row and index specified */
void BooleanMatrix::setRowInt(int row, int index, int value)
{
	// TO TRY EXCEPT THIS - index may be out of bounds
	int * p = this->getRow(row);
	p[index] = value;
}

/* Set a specific bit */
void BooleanMatrix::setBit(int row, int column, bool value)
{
	int * p = this->getRow(row);
	if (value)
		p[column / 32] = p[column / 32] | (1 << (column % 32  ));
	else
		p[column / 32] = p[column / 32] & (!(1 << (column % 32  )));
}	

/* Get the value of a bit */
bool BooleanMatrix::getBit(int row, int column)
{
	int * p = this->getRow(row);
	return (p[column / 32] >> (column % 32  )) & 1;
}


/* Return a pointer to the offset in the matrix buffer coresponding to the specific row index */
int * BooleanMatrix::getRow(int index)
{
	if (index <= 0)
		index = 0;
	else
	if (index >= this->height)
		index = this->height;
		
	return this->matrix[index];
}

/* Returns the number of  */
int BooleanMatrix::getNumberOnOffset(int row, int column, int length)
{
	if (column > 32)
		return 0;

	int nr = 0;
	for (int i = column; i < column + length; i++)
	{
		nr |= this->getBit(row, i) << (i-column);
	}

	return nr;
}