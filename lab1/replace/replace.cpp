#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "replace.h"

struct Args {
    std::string inputFileName;
    std::string outputFileName;
    std::string searchStringFileName;
    std::string replaceStringFileName;
};

std::optional<Args> parseArg(int argc, char* argv[]) {
    if (argc != 5) {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: replace.exe <in file name> <out file name>\n";
        return std::nullopt;
    };
    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    args.searchStringFileName = argv[3];
    args.replaceStringFileName = argv[4];

    return args;
};

void replace(std::ifstream& mask, std::ifstream& replacement, std::ifstream& input, std::ofstream& output)
{
    char ch1;
    char ch2;
    std::string maskString = "";
    std::string replacementString = "";
    std::getline(mask, maskString);
    maskString = maskString + "\n";
    std::getline(replacement, replacementString);

    for (std::string line; std::getline(input, line);)
    {
        std::string tempStringForReadingSimbols = "";
        int j = 0;
        ch2 = maskString[j];
        for (int i = 0; (i < line.size()); ++i) {
            ch1 = line[i];
            if (ch1 == ch2) {
                ++j;
                if (maskString[j] != '\n') {//если не последний символ в маске                                 
                    ch2 = maskString[j];
                    tempStringForReadingSimbols = tempStringForReadingSimbols + ch1;
                }
                else {//если последний символ в маске тогда записываем в output из replacement
                    output << replacementString;
                    j = 0;
                    ch2 = maskString[j];
                }
            }
            else {//если символы не совпали обнуляем счетчик по маске и записываем накопленные совпадения в out
                j = 0;
                ch2 = maskString[j];
                output << tempStringForReadingSimbols;
                output.put(ch1);              
            }
        };
        if (!input.eof()) {
            output.put('\n');
        };
    };
}

int main(int argc, char* argv[])
{
    //проверка правильности аргументов входной строки
    auto args = parseArg(argc, argv);
    if (!args) {
        return 1;
    }

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

    //открываем файл с маской
    std::ifstream mask;
    mask.open(args->searchStringFileName);
    if (!mask.is_open()) {
        std::cout << "Failed to open '" << args->searchStringFileName << "'for reading";
        return 1;
    };
    if (mask.eof()) {
        std::cout << "The search string file is empty";
        char ch;
        while (input.get(ch)) {
            if (!output.put(ch)) {
                break;
            }
        };
        return 0;
    };

    std::ifstream replacement;
    replacement.open(args->replaceStringFileName);
    if (!replacement.is_open()) {
        std::cout << "Failed to open '" << args->replaceStringFileName << "'for reading";
        return 1;
    };

    replace(mask, replacement, input, output);

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

