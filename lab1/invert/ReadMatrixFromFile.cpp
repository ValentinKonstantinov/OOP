#include "invert.h"

bool ReadMatrixFromFile(std::ifstream& input, float matrix[3][3])
{
	// не передавать 3 параметром размер std::array
	for (int i = 0; i < sizeMatrix; ++i)
	{
		for (int j = 0; j < sizeMatrix; ++j)
		{
			if (!(input >> matrix[i][j]))
			{
				return false;
			}
		}
	}
	// написать в 1 строчку без использования тернарного оператора
	return !input.eof() ? false : true;
}