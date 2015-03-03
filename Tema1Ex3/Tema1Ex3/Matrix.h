
/* Class that will contain the representation of a boolean matrix 
	Every operation is at the bit level
	We keep track of the bits through an dynamic allocated integer matrix
*/
class BooleanMatrix
{
public:
	//VARS
	int width, height;
	int integerDownsizedWidth;

	//FUNCTIONS
	BooleanMatrix(int width, int height);

	void setRow(int index, int values[]);
	void setRowInt(int row, int column, int value);
	void setBit(int row, int column, bool value);
	bool getBit(int row, int column);
	int * getRow(int index);

	BooleanMatrix operator+(const BooleanMatrix& B)
	{
		// THIS = A
		int i;

		if (this->height != B.width)
			throw 1;
		BooleanMatrix C(this->height, this->height);

		
		

		
		
		return C;
	}

private:
	int * matrix;

};