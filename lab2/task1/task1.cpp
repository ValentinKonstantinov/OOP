// task1.cpp : Defines the entry point for the console application.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <iterator>
#include "VectorProcessor.h"
using namespace std;

int main()
{

	vector<double> v;
	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(v));

	ProcessVector(v);
	copy(v.begin(), v.end(), ostream_iterator<double>(cout, " "));
	return 0;
}

