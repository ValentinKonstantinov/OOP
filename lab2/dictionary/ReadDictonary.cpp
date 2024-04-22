#include "ReadDictonary.h"

//optional 
bool ReadDictonary(std::string const& dictonaryFileDirrectory, Dictionary& dictonary)
{
    std::ifstream inFile;
    inFile.open(dictonaryFileDirrectory);
    if (!inFile.is_open())
    {
        std::cout << "Failed to open '" << dictonaryFileDirrectory << "' for reading\n";
        return false;
    }
    std::string word1;
    std::string word2;
    while (!inFile.eof())
    {
        if (inFile >> word1)
        {
            if (inFile >> word2)
            {
                dictonary.emplace(word1, word2);
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
