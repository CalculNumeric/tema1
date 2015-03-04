/*
	--- THE FOUR RUSSIANS - BOOLEAN MATRIX MULTIPLICATION ---
				- Implementation example -

	This example uses a maximum o
*/
#include "Matrix.h"
#define MatrixSizeW 5
#define MatrixSizeH 5

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
	cout << "Matrix A: \n";
	A << cout;
	cout << "Matrix B: \n";
	B << cout;
	cout << "Matrix A*B: \n";
	A*B << cout;

	cin >> i;
	return 0;
}