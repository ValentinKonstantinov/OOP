#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numbers>
#include "ReadVector.h"
using namespace std;

std::vector<double> ReadVector(std::istream& input)
{
	std::vector<double> numbers;
	copy(istream_iterator<double>(input), istream_iterator<double>(), back_inserter(numbers));
	return numbers;
}

