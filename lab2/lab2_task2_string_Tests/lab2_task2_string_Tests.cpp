#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../../Malov-labs/oop/catch2/catch.hpp"
#include "../../lab2/lab2_task2_FindAndReplace/FindAndReplase.h"
#include "../lab2_task2_FindAndReplace/ParseArg.h"


SCENARIO("an empty input remains an empty string")
{
	std::string inString = "";
	std::string search = "a";
	std::string replace = "s";
	std::string outString;
	outString = FindAndReplace(inString, search, replace);
	REQUIRE(outString == "");
}

//названия тестов информативнее по смыслу а не по факту
//классы эквивалентности для тестов
SCENARIO("replacing one character with one character")
{
	std::string inString = "a";
	std::string search = "a";
	std::string replace = "s";
	std::string outString;
	outString = FindAndReplace(inString, search, replace);
	REQUIRE(outString == "s");
}

SCENARIO("replacing one character with an empty string")
{
	std::string inString = "a";
	std::string search = "a";
	std::string replace = "";
	std::string outString;
	outString = FindAndReplace(inString, search, replace);
	REQUIRE(outString == "");
}

SCENARIO("search = empty")
{
	std::string inString = "a";
	std::string search = "";
	std::string replace = "a";
	std::string outString;
	outString = FindAndReplace(inString, search, replace);
	REQUIRE(outString == "a");
}

SCENARIO("correct return to the beginning of the comparison")
{
	std::string inString = "12312312345";
	std::string search = "1231234";
	std::string replace = "";
	std::string outString;
	outString = FindAndReplace(inString, search, replace);
	REQUIRE(outString == "1235");
}

SCENARIO("dont search in string")
{
	std::string inString = "345 6";
	std::string search = "1";
	std::string replace = "2";
	std::string outString;
	outString = FindAndReplace(inString, search, replace);
	REQUIRE(outString == "345 6");
}

SCENARIO("some searchs in string")
{
	std::string inString = "1 1 11";
	std::string search = "1";
	std::string replace = "2";
	std::string outString;
	outString = FindAndReplace(inString, search, replace);
	REQUIRE(outString == "2 2 22");
}
//более осмысленные данные