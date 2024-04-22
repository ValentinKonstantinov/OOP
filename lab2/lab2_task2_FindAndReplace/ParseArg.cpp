#include "ParseArg.h"

std::optional<Args> ParseArg(int argc, char* argv[], std::string& searchString, std::string& replacement)
{
    if (argc != 3)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: replace.exe <in file name> <out file name>\n";
        return std::nullopt;
    }
    Args args;
    args.searchString = argv[1];
    args.replaceString = argv[2];
    searchString = args.searchString;
    replacement = args.replaceString;
    return args;
}
