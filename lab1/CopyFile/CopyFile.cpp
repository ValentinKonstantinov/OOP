#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "CopyFile.h"


int main(int argc, char* argv[])
{
    //чтение и проверка правильности аргументов входной строки
    auto args = parseArg(argc, argv);
    if (!args) {
        return 1;
    }

    //открываем входной файл в режиме чтения
    std::ifstream input;
    input.open(args->inputFileName);
    if (!input.is_open()) {
        std::cout << "Failed to open '" << args->inputFileName << "' for reading\n";
        return 1;
    };

    //открываем выходной файл в режиме записи
    std::ofstream output;
    output.open(args->outputFileName);
    if (!output.is_open()) {
        std::cout << "Failed to open '" << args->outputFileName << "'for writing";
        return 1;
    };

    CopyStream(input, output);

    //проверка корректности окончания чтения
    if (input.bad()) {
        std::cout << "Error read data to input file\n";
        return 1;
    }
    //output.flush() дописывает все из буфера в выходеной поток, используем для проверки окончанния записи
    if (!output.flush()) {
        std::cout << "Error write data to output file\n";
        return 1;
    };

    return 0;
}
