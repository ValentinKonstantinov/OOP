#include "InvertMatrix.h"
bool InvertMatrix(float matrix[3][3], std::vector<std::vector<float>>& inverseMatrix)
{
	const int sizeMatrix = 3;
	float determinantOfMatrix = GetDeterminantOfMatrix(matrix);
	if (!determinantOfMatrix)
	{
		std::cout << "determinantOfMatrix = 0, no inverse matrix" << std::endl;
		return false;
	}
	auto matrixOfMinors = GetMatrixOfMinors(matrix);
	auto algebraicComplementMatrix = GetAlgebraicComplementMatrix(matrixOfMinors);
	auto transposedAlgebraicComplementMatrix = GetTransposedAlgebraicComplementMatrix(algebraicComplementMatrix);
	inverseMatrix = GetInverseMatrix(determinantOfMatrix, transposedAlgebraicComplementMatrix);

	return true;
}