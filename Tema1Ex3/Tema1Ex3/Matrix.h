#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

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
	void orRow(int index, int values[]);
	void setRowInt(int row, int column, int value);
	void setBit(int row, int column, bool value);
	bool getBit(int row, int column);
	int * getRow(int index);
	int getNumberOnOffset(int row, int column, int length);

	BooleanMatrix operator*(BooleanMatrix& B)
	{
		if (this->height != B.width)
			throw 1;

		BooleanMatrix * C, * cache;
		int i, j, k, l, cacheFrameHeight, index;
		int nrFrames;
		unsigned int frameSize;

		// If the matrixes can't be multiplied
		C = new BooleanMatrix(this->height, this->height);

		// malloc space for the cache for each division
		frameSize = (int)log2((double)B.height);
		nrFrames = (B.height / frameSize + 1);
		cacheFrameHeight = pow((double)2, (double)frameSize);
		cache = new BooleanMatrix(B.integerDownsizedWidth, cacheFrameHeight * nrFrames);

		// calculating  
		for (i = 0; i < nrFrames; i++)
		{
			// for each possible combination of rows in the frame
			for (j = 0; j < cacheFrameHeight; j++)
			{
				// for each row in the frame
				for (k = 0; k < frameSize; k++)
				{
					if (j >> k & 1) // if the current row is selected in the combination
					{
						// OR the current row in the result
						for (l = 0; l < B.integerDownsizedWidth; l++)
						{
							cache->getRow(i * cacheFrameHeight + j)[l] |= B.getRow(k + (i * frameSize))[l];
						}
					}
				}
			}
		}

		for (i = 0; i < this->height; i++)
		{
			for (j = 0; j < nrFrames; j++)
			{
				if (j == nrFrames-1)
					index = this->getNumberOnOffset(i, j*frameSize, this->width % frameSize) << (frameSize - (this->width % frameSize));
				else
					index = this->getNumberOnOffset(i, j*frameSize, frameSize);

				C->orRow(i, cache->getRow(index + j*cacheFrameHeight));
			}
		}

		return *C;
	}

	ostream& operator<<(ostream& os)
	{
		int i, j;
		for (i = 0; i < this->height; i++)
		{
			for (j = 0; j < this->width; j++)
			{
				os << this->getBit(i, j) << " ";
			}
			os << "\n";
		}
		return os;
	}

private:
	int ** matrix;

};
