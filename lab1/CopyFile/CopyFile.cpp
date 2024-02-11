#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "CopyFile.h"
struct Args {
    std::string inputFileName;
    std::string outputFileName;
};

std::optional<Args> parseArg(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: CopuFile.exe <in file name> <out file name>\n";
        return std::nullopt;
    };
    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    return args;
};

void CopyStrims(std::ifstream& input, std::ofstream& output)
{
    //копируем входной файл в выходной
    char ch;
    while (input.get(ch)) {
        if (!output.put(ch)) {
            break;
        }
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

    CopyStrims(input, output);

    if (input.bad()) {
        std::cout << "Error read data to input file\n";
        return 1;
    }
    /*
    std::cout << argc << "\n";
    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    };
    */

    if (!output.flush()) {
        std::cout << "Error write data to output file\n";
        return 1;
    };
    return 0;
}
