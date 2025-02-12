#pragma once
#include <iostream>
#include <fstream>
#include <optional>
#include <string>
//разделить заголовочные файлы на модули
//очиистить лишние include
struct Args
{
	std::string searchString;
	std::string replaceString;
	std::ifstream in;
	std::ofstream out;
};
int main(int argc, char* argv[]);
