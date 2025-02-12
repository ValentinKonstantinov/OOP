#include "Replace.h"
#include "ParseArg.h"
#include "StringsReplacement.h"
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
// на вход 2 файла и 2 строки(что ищем и на что меняем строки)
// имена функций с заглавных
// подключить автоформатирование CTRL + K далее CTRL +D
// передавать из функции в функцию Args

int main(int argc, char* argv[])
{
	Args args;
	// проверка наличия аргументов входной строки
	bool isParsing = ParseArg(argc, argv, args);
	if (!isParsing)
	{
		return 1;
	};

	bool correct = StringsReplacement(args);
	if (!correct)
	{
		return 1;
	};
	return 0;
}
