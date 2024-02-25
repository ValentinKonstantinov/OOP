#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <cassert>
#include <limits>
#include "invert.h"

struct Args
{
    std::string inputFileName;
};

std::optional<Args> ParseArg(int argc, char* argv[],
    std::ifstream& input)
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: replace.exe <in file name> <out file name>\n";
        return std::nullopt;
    }

    Args args;
    args.inputFileName = argv[1];

    input.open(args.inputFileName);
    if (!input.is_open())
    {
        std::cout << "Failed to open '" << args.inputFileName << "' for reading\n";
        return std::nullopt;
    }

    return args;
}

bool matrixInitialization(std::ifstream& input, float matrix[3][3], int sizeMatrix)
{
    float tempFloat;
    for (int i = 0; i < sizeMatrix; ++i)
    {
        for (int j = 0; j < sizeMatrix; ++j)
        {
            if (input >> tempFloat)
            {
                matrix[i][j] = tempFloat;
            }
            else
            {
                return false;
            }
        }
    }
    if (!input.eof())
    {
        return false;
    }
    else
    {
        return true;
    }
}

float getDeterminantOfMatrix(float matrix[3][3])
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

void getMatrixOfMinors(float matrix[3][3], float matrixOfMinors[3][3])
{
    matrixOfMinors[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
    matrixOfMinors[0][1] = matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0];
    matrixOfMinors[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
    matrixOfMinors[1][0] = matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1];
    matrixOfMinors[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
    matrixOfMinors[1][2] = matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0];
    matrixOfMinors[2][0] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
    matrixOfMinors[2][1] = matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0];
    matrixOfMinors[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

void getAlgebraicComplementMatrix(float matrixOfMinors[3][3], float algebraicComplementMatrix[3][3])
{
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
}

void getTransposedAlgebraicComplementMatrix(float algebraicComplementMatrix[3][3], float transposedAlgebraicComplementMatrix[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            transposedAlgebraicComplementMatrix[i][j] = algebraicComplementMatrix[j][i];
        }
    }
}
void getInverseMatrix(float determinantOfMatrix, float transposedAlgebraicComplementMatrix[3][3], float inverseMatrix[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            inverseMatrix[i][j] = transposedAlgebraicComplementMatrix[i][j] / determinantOfMatrix;
        }
    }
}

void printMatrix(float inverseMatrix[3][3])
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

bool InvertMatrix(float  matrix[3][3], float  inverseMatrix[3][3])
{
    const int sizeMatrix = 3;
    float determinantOfMatrix = getDeterminantOfMatrix(matrix);
    if (!determinantOfMatrix)
    {
        std::cout << "determinantOfMatrix = 0, no inverse matrix" << std::endl;
        return false;
    }
    float matrixOfMinors[sizeMatrix][sizeMatrix]{};
    getMatrixOfMinors(matrix, matrixOfMinors);
    float algebraicComplementMatrix[sizeMatrix][sizeMatrix]{};
    getAlgebraicComplementMatrix(matrixOfMinors, algebraicComplementMatrix);
    float transposedAlgebraicComplementMatrix[sizeMatrix][sizeMatrix]{};
    getTransposedAlgebraicComplementMatrix(algebraicComplementMatrix, transposedAlgebraicComplementMatrix);
    getInverseMatrix(determinantOfMatrix, transposedAlgebraicComplementMatrix, inverseMatrix);
    printMatrix(inverseMatrix);
    return true;
}

int main(int argc, char* argv[])
{
    std::ifstream input;
    auto args = ParseArg(argc, argv, input);
    if (!args)
    { 
        std::cout << "Error" << std::endl;
        return 1;
    }
    const int sizeMatrix = 3;
    float matrix[sizeMatrix][sizeMatrix];
    bool correct = matrixInitialization(input, matrix, sizeMatrix);
    if (!correct)
    {
        return 1;
    }

    float inverseMatrix[sizeMatrix][sizeMatrix]{};
    bool correct = InvertMatrix(matrix, inverseMatrix);
    if (!correct)
    {
        return 1;
    }
    return 0;
}
