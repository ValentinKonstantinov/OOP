#include <iostream>
#include <ostream>

#include <vector>

#define CATCH_CONFIG_MAIN
#include "../../../Malov-labs/oop/catch2/catch.hpp"
#include "../vector/ProcessVector.h"
#include "../vector/ReadVector.h"
#include "../vector/OutputSortVector.h"

SCENARIO("an empty input remains an empty vector")
{
	std::stringstream input("");
	auto v = ReadVector(input);
	REQUIRE(v.empty());//метод empty()
}

SCENARIO("1 number input remains 1 number vector")
{
	std::stringstream input("1");
	auto v = ReadVector(input);
	REQUIRE(v == std::vector<double>{1.0});
}


SCENARIO("several numbers input make several number vector")
{
	std::vector<double> v = {};
	std::stringstream input("1 2.1 3.4444");
	v = ReadVector(input);
	REQUIRE(v.size() == 3);
	REQUIRE(v[0] == 1);
	REQUIRE(v[1] == 2.1);
	REQUIRE(v[2] == 3.4444);
}

SCENARIO("empty vector remains empty vector")
{
	std::vector<double> v = {};
	ProcessVector(v);
	REQUIRE(v.size() == 0);
}
SCENARIO("vector of one element is equal to itself")
{
	std::vector<double> v = {2};
	ProcessVector(v);
	REQUIRE(v[0] == 2);
}

// название дублирует код и не объясняет 
SCENARIO("Multiply each element of an array of three integers by the maximum element of the original array and divide by the minimum element of the original array ")
{
	std::vector<double> v = { 1, 2, 3 };
	ProcessVector(v);
	REQUIRE(v[0] == 3);
	REQUIRE(v[1] == 6);
	REQUIRE(v[2] == 9);
}
//
SCENARIO("Multiply each element of the array of three fractional numbers by the maximum element of the original array and divide by the minimum element of the original array")
{
	std::vector<double> v = { 3, 4.5, 5.1 };
	ProcessVector(v);
	REQUIRE(v[0] == 3 * 5.1 / 3);
	REQUIRE(v[1] == 4.5 * 5.1 / 3);
	REQUIRE(v[2] == 5.1 * 5.1 / 3);
}

SCENARIO("empty in output")
{
	std::vector<double> v = {};
	std::ostringstream output;
	OutputSortVector(v, output);
	REQUIRE(output.str() == "");
}

SCENARIO("sorted vector in output")
{
	std::vector<double> v = {1, 2, 3};
	std::ostringstream output;
	OutputSortVector(v, output);
	REQUIRE(output.str() == "1 2 3 ");
}

SCENARIO("dont sorted vector in output")
{
	std::vector<double> v = { 3, 2, 1 };
	std::ostringstream output;
	OutputSortVector(v, output);
	REQUIRE(output.str() == "1 2 3 ");
}

SCENARIO("vector of numbers with large fractional part in output")
{
	std::vector<double> v = { 1.11111, 2.22222, 3.33333 };
	std::ostringstream output;
	OutputSortVector(v, output);
	REQUIRE(output.str() == "1.11 2.22 3.33 ");
}