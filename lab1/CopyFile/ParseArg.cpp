#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "CopyFile.h"


std::optional<Args> parseArg(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: CopyFile.exe <in file name> <out file name>\n";
        return std::nullopt;
    };
    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    return args;
};