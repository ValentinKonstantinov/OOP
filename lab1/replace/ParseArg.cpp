#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include "ParseArg.h"

bool ParseArg(int argc, char* argv[], Args& args)
{
	if (argc != 5)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: replace.exe <in file name> <out file name>\n";
		return false;
	}

	args.searchString = argv[3];
	args.replaceString = argv[4];

	args.in.open(argv[1]);
	if (!args.in.is_open())
	{
		std::cout << "Failed to open '" << argv[1] << "' for reading\n";
		return false;
	}

	args.out.open(argv[2]);
	if (!args.out.is_open())
	{
		std::cout << "Failed to open '" << argv[2] << "'for writing";
		return false;
	}

	return true;
}