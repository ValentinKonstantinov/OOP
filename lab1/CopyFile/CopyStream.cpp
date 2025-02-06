#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "CopyFile.h"


void CopyStream(std::ifstream& input, std::ofstream& output)
{
    //копируем входной поток привязанный к одному файлу в выходной привязанный к другому
    char ch;
    while (input.get(ch)) {
        if (!output.put(ch)) {
            break;
        }
    };
}
