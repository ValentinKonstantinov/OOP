#include "GetAlgebraicComplementMatrix.h"
std::vector<std::vector<float>> GetAlgebraicComplementMatrix(const std::vector<std::vector<float>> matrixOfMinors)
{
	std::vector<std::vector<float>> algebraicComplementMatrix(3, std::vector<float>(3));
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (((i % 2 == 0) && (j % 2 != 0)) || ((i % 2 != 0) && (j % 2 == 0)))
			{
				algebraicComplementMatrix[i][j] = -matrixOfMinors[i][j];
			}
			else
			{
				algebraicComplementMatrix[i][j] = matrixOfMinors[i][j];
			}
		}
	}
	return algebraicComplementMatrix;
}