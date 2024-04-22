#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <cassert>
#include <limits>
#include "invert.h"

//std::arrray <>

struct Args
{
    std::string inputFileName;
};

// 
std::optional<Args> ParseArg(int argc, char* argv[], std::ifstream& input)
{
    //не подавать ссылку на файл, разложить на 2 функции
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

//readMatrixfrom file
bool MatrixInitialization(std::ifstream& input, float matrix[3][3], int sizeMatrix)
{
    //не передавать 3 параметром размер
    float tempFloat;
    for (int i = 0; i < sizeMatrix; ++i)
    {
        for (int j = 0; j < sizeMatrix; ++j)
        {
            if (input >> tempFloat)
            {
                //избавится от переменной tempFloat
                matrix[i][j] = tempFloat;
            }
            else
            {
                return false;
            }
        }
    }
    //написать в 1 строчку без использования тернарного оператора
    if (!input.eof())
    {
        return false;
    }
    else
    {
        return true;
    }
}

// не давать изменять массив
float GetDeterminantOfMatrix(float matrix[3][3])
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

//не давать изменять массив объявить внутри и отдать ретурном
void GetMatrixOfMinors(float matrix[3][3], float matrixOfMinors[3][3])
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

//анналогично
void GetAlgebraicComplementMatrix(float matrixOfMinors[3][3], float algebraicComplementMatrix[3][3])
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

// функция называется неправильно назвать более общим
void GetTransposedAlgebraicComplementMatrix(float algebraicComplementMatrix[3][3], float transposedAlgebraicComplementMatrix[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            transposedAlgebraicComplementMatrix[i][j] = algebraicComplementMatrix[j][i];
        }
    }
}
// функция называется неправильно назвать более общим
void GetInverseMatrix(float determinantOfMatrix, float transposedAlgebraicComplementMatrix[3][3], float inverseMatrix[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            inverseMatrix[i][j] = transposedAlgebraicComplementMatrix[i][j] / determinantOfMatrix;
        }
    }
}

void PrintMatrix(float inverseMatrix[3][3])
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
    float determinantOfMatrix = GetDeterminantOfMatrix(matrix);
    if (!determinantOfMatrix)
    {
        std::cout << "determinantOfMatrix = 0, no inverse matrix" << std::endl;
        return false;
    }
    float matrixOfMinors[sizeMatrix][sizeMatrix]{};
    GetMatrixOfMinors(matrix, matrixOfMinors);
    float algebraicComplementMatrix[sizeMatrix][sizeMatrix]{};
    GetAlgebraicComplementMatrix(matrixOfMinors, algebraicComplementMatrix);
    float transposedAlgebraicComplementMatrix[sizeMatrix][sizeMatrix]{};
    GetTransposedAlgebraicComplementMatrix(algebraicComplementMatrix, transposedAlgebraicComplementMatrix);
    GetInverseMatrix(determinantOfMatrix, transposedAlgebraicComplementMatrix, inverseMatrix);
    PrintMatrix(inverseMatrix);
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
    bool correctMatrixInitialization = MatrixInitialization(input, matrix, sizeMatrix);
    if (!correctMatrixInitialization)
    {
        return 1;
    }

    float inverseMatrix[sizeMatrix][sizeMatrix]{};
    bool correctInvertMatrix = InvertMatrix(matrix, inverseMatrix);
    if (!correctInvertMatrix)
    {
        return 1;
    }
    return 0;
}
