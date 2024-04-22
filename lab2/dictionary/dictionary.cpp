#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <map>
#include <Windows.h>
#include "ReadDictonary.h"
#include "ParseArg.h"
#include "WorkingWithADictionary.h"
#include "dictionary.h"

//упростить main
int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool correct = DictionaryWorking(argc, argv);
    if (!correct)
    {
        std::cout << "dictionary error" << std::endl;
        return 1;
    }

    return 0;
}
