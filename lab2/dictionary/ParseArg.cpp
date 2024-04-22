#include "ParseArg.h"

bool ParseArg(int argc, char* argv[], std::string& dictonaryFileDirrectory)
{
    
    if (argc != 2)
    {
        std::cout << "Invalid arguments count\n";
        return false;
    };
    dictonaryFileDirrectory = argv[1];
    
    return true;
}
