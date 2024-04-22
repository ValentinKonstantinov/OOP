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

void OutputSortVector(std::vector<double> v, std::ostream& output)
{
	output << std::setprecision(3);
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), std::ostream_iterator<double>(output, " "));
}
