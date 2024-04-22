#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "replace.h"
//на вход 2 файла и 2 строки(что ищем и на что меняем строки)
//имена функций с заглавных
//подключить автоформатирование
struct Args
{
    std::string inputFileName;
    std::string outputFileName;
    std::string searchString;
    std::string replaceString;
};

std::optional<Args> ParseArg(int argc, char* argv[],
    std::ifstream& input, std::ofstream& output, std::string &searchString, std::string &replacement)
{
    if (argc != 5)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: replace.exe <in file name> <out file name>\n";
        return std::nullopt;
    }
    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    args.searchString = argv[3];
    args.replaceString = argv[4];
    input.open(args.inputFileName);
    if (!input.is_open())
    {
        std::cout << "Failed to open '" << args.inputFileName << "' for reading\n";
        return std::nullopt;
    }
 
    output.open(args.outputFileName);
    if (!output.is_open())
    {
        std::cout << "Failed to open '" << args.outputFileName << "'for writing";
        return std::nullopt;
    }
    searchString = args.searchString;
    replacement = args.replaceString;
    return args;
}

std::string ReplaceLine(const std::string& subject, const std::string& searchString, const std::string& replacement)
{
    size_t pos = 0;
    std::string result;
    while (pos < subject.length())
    {
        // Находим позицию искомой строки, начиная с pos
        size_t foundPos = subject.find(searchString, pos);
        // В результирующую строку записываем текст из диапазона [pos,foundPos)
        if (foundPos != SIZE_MAX)
        {
            result.append(subject, pos, foundPos - pos);
            result.append(replacement);
            pos = foundPos + searchString.length();
        }
        else
        {
            result.append(subject, pos, foundPos - pos);
            pos = foundPos;
        }
    }
    return result;
}

void Replace(std::ifstream& input, std::ostream& output, const std::string& searchString, const std::string& replacement)
{
    //
    for (std::string line; std::getline(input, line);)
    {
        output << ReplaceLine(line, searchString, replacement);
        if (!input.eof())
        {
            output << "\n";
        }         
    }
}


// передать по отдельности 4 параметра args->....
bool StringReplacement(std::ifstream& input, std::ofstream& output, const std::string& searchString, const std::string& replacement)
{
    if (searchString.length() == 0)
    {
        char ch;
        while (input.get(ch))
        {
            if (!output.put(ch))
            {
                break;
            }
        }
        return true;
    }    

    Replace(input, output, searchString, replacement);

    if (input.bad())
    {
        std::cout << "Error read data to input file\n";
        return false;
    }

    if (!output.flush())
    {
        std::cout << "Error write data to output file\n";
        return false;
    }

    return true;
}

int main(int argc, char* argv[])
{   std::ifstream input;
    std::ofstream output;
    std::string searchString;
    std::string replacement;
    //проверка наличия аргументов входной строки 
    auto args = ParseArg(argc, argv, input, output, searchString, replacement);
    if (!args)
    {
        return 1;
    };

    //возвращать bool (true в случае успеха)
    bool correct = StringReplacement(input, output, searchString, replacement);
    if (!correct)
    {
        return 1;
    };
    return 0;
}

