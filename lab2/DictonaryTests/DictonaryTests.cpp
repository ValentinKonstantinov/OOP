#include <iostream>


#define CATCH_CONFIG_MAIN
#include "../../../Malov-labs/oop/catch2/catch.hpp"
#include "../dictionary/ParseArg.h"
#include "../dictionary/ReadDictonary.h"
#include "../dictionary/WorkingWithADictionary.h"

SCENARIO("empty Dictonary file")
{
    std::string fileDictonary;
	fileDictonary = "C:\\IPS\\OOP\\labs\\lab2\\dictionary\\emptyDictonary.txt";
	Dictionary dictonary;
	bool correct = ReadDictonary(fileDictonary, dictonary);

	REQUIRE(dictonary.empty() == true);
}

SCENARIO("invalid Dictonary file")
{
	std::string fileDictonary;
	fileDictonary = "C:\\IPS\\OOP\\labs\\lab2\\dictionary\\invalidDictonary.txt";
	Dictionary dictonary;
	bool correct = ReadDictonary(fileDictonary, dictonary);
	REQUIRE(correct == false);
	REQUIRE(dictonary.empty() == true);
}

SCENARIO("recording 1 object in Dictonary file")
{
	std::string fileDictonary;
	fileDictonary = "C:\\IPS\\OOP\\labs\\lab2\\dictionary\\1WorldInDictonary.txt";
	Dictionary dictonary;
	bool correct = ReadDictonary(fileDictonary, dictonary);
	REQUIRE(correct == true);
	REQUIRE(dictonary.size() == 1);
	REQUIRE(dictonary["cat"] == "кошка");
}

SCENARIO("recording 3 objects in Dictonary file")
{
	std::string fileDictonary;
	fileDictonary = "C:\\IPS\\OOP\\labs\\lab2\\dictionary\\3WorldInDictonary.txt";
	Dictionary dictonary;
	bool correct = ReadDictonary(fileDictonary, dictonary);
	REQUIRE(correct == true);
	REQUIRE(dictonary.size() == 3);
	REQUIRE(dictonary["cat"] == "кошка");
	REQUIRE(dictonary["dog"] == "собака");
	REQUIRE(dictonary["hello"] == "привет");
}

SCENARIO("search valid word in Dictonary")
{
	Dictionary dictonary;
	std::istringstream input{ "cat" };
	std::ostringstream output;
	IO io{ input, output };
	dictonary.emplace("cat", "кошка");
	WorkingWithDictionary(dictonary, io);
	REQUIRE(output.str() == "кошка");
}

SCENARIO("search invalid word in Dictonary")
{
	Dictionary dictonary;
	std::istringstream input {"cat\nкошка"};
	std::ostringstream output;
	IO io{ input, output };
	WorkingWithDictionary(dictonary, io);
	REQUIRE(dictonary.size() == 1);
	std::cout << dictonary["cat"] << " кошка";
	REQUIRE(dictonary["cat"] == "кошка");
}

SCENARIO("Save dictonary in file")
{
	Dictionary dictonary;
	std::string fileDictonary;
	fileDictonary = "C:\\IPS\\OOP\\labs\\lab2\\dictionary\\Dictonary.txt";
	dictonary.emplace("cat", "кошка");
	bool correct = SaveDictionary(dictonary, fileDictonary);
	std::ifstream in;
	in.open("Dictonary.txt");
	REQUIRE(!in.eof());
}