#include "GetDeterminantOfMatrix.h"
float GetDeterminantOfMatrix(const float matrix[3][3])
{
	float determinantOfMatrix = 0;
	int temp = 0;

	determinantOfMatrix = determinantOfMatrix + matrix[0][0] * matrix[1][1] * matrix[2][2];
	determinantOfMatrix = determinantOfMatrix + matrix[0][1] * matrix[1][2] * matrix[2][0];
	determinantOfMatrix = determinantOfMatrix + matrix[0][2] * matrix[1][0] * matrix[2][1];
	determinantOfMatrix = determinantOfMatrix - matrix[0][2] * matrix[1][1] * matrix[2][0];
	determinantOfMatrix = determinantOfMatrix - matrix[0][1] * matrix[1][0] * matrix[2][2];
	determinantOfMatrix = determinantOfMatrix - matrix[0][0] * matrix[1][2] * matrix[2][1];

	return determinantOfMatrix;
}