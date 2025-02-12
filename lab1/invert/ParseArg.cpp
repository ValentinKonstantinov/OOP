#include "ParseArg.h"

Args ParseArg(int argc, char* argv[])
{
	Args args;
	// не подавать ссылку на файл
	if (argc != 2)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: invert.exe <in file name> <out file name>\n";
		args.isCorrect = false;
		return args;
	}

	args.input.open(argv[1]);
	if (!args.input.is_open())
	{
		std::cout << "Failed to open '" << argv[1] << "' for reading\n";
		args.isCorrect = false;
		return args;
	}
	args.isCorrect = true;
	return args;
}