#include "invert.h"
#include "InvertMatrix.h"
#include "ParseArg.h"
// не давать изменять массив
// не давать изменять массив объявить внутри и отдать ретурном

namespace
{
void PrintMatrix(const std::vector<std::vector<float>> inverseMatrix)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout.precision(3);
			std::cout << std::fixed << inverseMatrix[i][j];
			if (j != 2)
			{
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
}
} // namespace

int main(int argc, char* argv[])
{
	Args args = ParseArg(argc, argv);
	if (!args.isCorrect)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	float matrix[sizeMatrix][sizeMatrix];
	bool correctMatrixInitialization = ReadMatrixFromFile(args.input, matrix);
	if (!correctMatrixInitialization)
	{
		return 1;
	}

	std::vector<std::vector<float>> inverseMatrix(3, std::vector<float>(3));
	bool correctInvertMatrix = InvertMatrix(matrix, inverseMatrix);
	if (!correctInvertMatrix)
	{
		return 1;
	}
	PrintMatrix(inverseMatrix);
	return 0;
}
