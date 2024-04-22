#pragma once
#include <iostream>
#include <fstream>
#include <optional>

struct Args
{
    std::string inputDictonary;
};

bool ParseArg(int argc, char* argv[], std::string& dictonaryFileDirrectory);