/*
	--- THE FOUR RUSSIANS - BOOLEAN MATRIX MULTIPLICATION ---
				- Implementation example -

	This example uses a maximum o
*/
#include "Matrix.h"
#include <stdlib.h>
#include <iostream>
#define MatrixSizeW 5
#define MatrixSizeH 5

using namespace std;

int main()
{
	int i;
	BooleanMatrix A(MatrixSizeW, MatrixSizeH), B(MatrixSizeW, MatrixSizeH);
	
	// Initialize matrix
	for (i = 1; i <= 5; i++)
	{
		A.setRowInt(i - 1, 0, i);
		B.setRowInt(i - 1, 0, i + 2);
	}

	// Print matrixes
	//cout << "Matrix A: \n" << A;
	//cout << "Matrix B: \n" << B;
	//cout << "Matrix C: \n" << A*B;

	return 0;
}