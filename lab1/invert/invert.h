#pragma once
#include <cassert>
#include <fstream>
#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <vector>
const int sizeMatrix = 3;
struct Args
{
	std::ifstream input;
	bool isCorrect;
};

int main(int argc, char* argv[]);

bool ReadMatrixFromFile(std::ifstream& input, float matrix[3][3]);
