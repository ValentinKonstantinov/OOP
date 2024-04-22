#include <vector>
#include <fstream>
#include <optional>
#include <string>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <limits>
#include <numbers>
#include "ProcessVector.h"
#include "ReadVector.h"
#include "vector.h"
#include "OutputSortVector.h"
using namespace std;
/*Умножить каждый элемент массива на максимальный элемент исходного массива
и разделить на минимальный элемент исходного массива*/
//бонус начисляется за вывод элементов массива в порядке возрастания их значений.


int main()
{
	vector<double> v = ReadVector(std::cin);
	ProcessVector(v);
	OutputSortVector(v, std::cout);
	return 0;
}
