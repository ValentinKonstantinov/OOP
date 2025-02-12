#include "ReplaceLine.h"
#include <fstream>
#include <iostream>
#include <string>

std::string ReplaceLine(const std::string& subject, const std::string& searchString, const std::string& replacement)
{
	size_t pos = 0;
	std::string result;
	while (pos < subject.size())
	{
		// Находим позицию искомой строки, начиная с pos
		size_t foundPos = subject.find(searchString, pos);
		// В результирующую строку записываем текст из диапазона [pos,foundPos)
		result.append(subject, pos, foundPos - pos);
		// std::string::npos
		if (foundPos != SIZE_MAX)
		{
			result.append(replacement);
			pos = foundPos + searchString.size();
		}
		else
		{
			pos = foundPos;
		}
		
	}
	return result;
}
