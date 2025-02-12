#include "GetInverseMatrix.h"
std::vector<std::vector<float>> GetInverseMatrix(float determinantOfMatrix, const std::vector<std::vector<float>> transposedAlgebraicComplementMatrix)
{
	std::vector<std::vector<float>> inverseMatrix(3, std::vector<float>(3));
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			inverseMatrix[i][j] = transposedAlgebraicComplementMatrix[i][j] / determinantOfMatrix;
		}
	}
	return inverseMatrix;
}