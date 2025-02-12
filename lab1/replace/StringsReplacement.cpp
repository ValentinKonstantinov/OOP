#include <iostream>
#include <fstream>
#include <string>
#include "StringsReplacement.h"
	//ifsteam на istream
bool StringsReplacement(Args& args)
{
    //искомая строка — пустая строка
	if (args.searchString.length() == 0)
    {
        char ch;
		while (args.in.get(ch))
        {
			if (!args.out.put(ch))
            {
                break;
            }
        }
        return true;
    }
    //замена
	for (std::string line; std::getline(args.in, line);)
    {
		args.out << ReplaceLine(line, args.searchString, args.replaceString);
		if (!args.in.eof())
        {
			args.out << "\n";
        }
    }

    //проверки успешности чтения и записи
	if (args.in.bad())
    {
        std::cout << "Error read data to input file\n";
        return false;
    }

    //не пренебрегать при записи в файл!!!!!!!!!!!!!!!!!!!!!!!!!(Дописывает в файл из буфера)!!!!!!!!!!!
	if (!args.out.flush())
    {
        std::cout << "Error write data to output file\n";
        return false;
    }

    return true;
}