#include "GetTransposedAlgebraicComplementMatrix.h"
std::vector<std::vector<float>> GetTransposedAlgebraicComplementMatrix(const std::vector<std::vector<float>> algebraicComplementMatrix)
{
	std::vector<std::vector<float>> transposedAlgebraicComplementMatrix(3, std::vector<float>(3));
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			transposedAlgebraicComplementMatrix[i][j] = algebraicComplementMatrix[j][i];
		}
	}
	return transposedAlgebraicComplementMatrix;
}