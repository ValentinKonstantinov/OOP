#include "GetMatrixOfMinors.h"
std::vector<std::vector<float>> GetMatrixOfMinors(const float matrix[3][3])
{
	std::vector<std::vector<float>> matrixOfMinors(3, std::vector<float>(3));
	matrixOfMinors[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
	matrixOfMinors[0][1] = matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0];
	matrixOfMinors[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
	matrixOfMinors[1][0] = matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1];
	matrixOfMinors[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
	matrixOfMinors[1][2] = matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0];
	matrixOfMinors[2][0] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
	matrixOfMinors[2][1] = matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0];
	matrixOfMinors[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	return matrixOfMinors;
}