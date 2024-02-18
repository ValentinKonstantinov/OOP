#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "replace.h"
//на вход 2 файла и 2 строки(что ищем и на что меняем строки)
//имена функций с заглавных
//подключить автоформатирование
struct Args {
    std::string inputFileName;
    std::string outputFileName;
    std::string searchString;
    std::string replaceString;
};

std::optional<Args> ParseArg(int argc, char* argv[]) {
    if (argc != 5) {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: replace.exe <in file name> <out file name>\n";
        return std::nullopt;
    };
    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    args.searchString = argv[3];
    args.replaceString = argv[4];

    return args;
};

void CharacterComparison(char& ch1, char& ch2, int& j, std::string& searchString, std::string& tempStringForReadingSimbols, std::ofstream& output, std::string& replacement)
{
    if (ch1 == ch2) {
        ++j;
        if (searchString[j] != '\n') {//если не последний символ в искомой строке                                
            ch2 = searchString[j];
            tempStringForReadingSimbols = tempStringForReadingSimbols + ch1;
        }
        else {//если последний символ в искомой строке тогда записываем в output из replacement
            output << replacement;
            j = 0;
            ch2 = searchString[j];
        }
    }
    else {//если символы не совпали обнуляем счетчик по искомой строке и записываем накопленные совпадения в out
        j = 0;
        ch2 = searchString[j];
        output << tempStringForReadingSimbols;
        output.put(ch1);
    }
}

void ReplaceLine(char& ch2, std::string& searchString, std::string& line, char& ch1, std::ofstream& output, std::string& replacement, std::ifstream& input)
{
    std::string tempStringForReadingSimbols = "";
    int j = 0;
    ch2 = searchString[j];
    for (int i = 0; (i < line.size()); ++i) {
        ch1 = line[i];
        CharacterComparison(ch1, ch2, j, searchString, tempStringForReadingSimbols, output, replacement);
    };
    if (!input.eof()) {
        output.put('\n');
    };
}

void Replace(std::string& searchString, std::string& replacement, std::ifstream& input, std::ofstream& output)
{
    char ch1;
    char ch2;
    for (std::string line; std::getline(input, line);)
    {
        ReplaceLine(ch2, searchString, line, ch1, output, replacement, input);
    };
};

int StringReplacement(std::optional<Args> args)
{
    //вфделить функцию которая выполняет 
    //открываем входной файл
    std::ifstream input;
    input.open(args->inputFileName);
    if (!input.is_open()) {
        std::cout << "Failed to open '" << args->inputFileName << "' for reading\n";
        return 1;
    };

    //открываем выходной файл
    std::ofstream output;
    output.open(args->outputFileName);
    if (!output.is_open()) {
        std::cout << "Failed to open '" << args->outputFileName << "'for writing";
        return 1;
    };

    std::string searchString = args->searchString;
    if (searchString.length() == 0) {
        char ch;
        while (input.get(ch)) {
            if (!output.put(ch)) {
                break;
            }
        };
        return 0;
    };
    searchString = searchString + "\n";

    std::string replacement = args->replaceString;

    Replace(searchString, replacement, input, output);

    if (input.bad()) {
        std::cout << "Error read data to input file\n";
        return 1;
    };

    if (!output.flush()) {
        std::cout << "Error write data to output file\n";
        return 1;
    };

    return 0;
}

int main(int argc, char* argv[])
{
    //проверка наличия аргументов входной строки 
    auto args = ParseArg(argc, argv);
    if (!args) {
        return 1;
    };
    auto correct = StringReplacement(args);
    if (correct) {
        return 1;
    };
    return 0;
}

