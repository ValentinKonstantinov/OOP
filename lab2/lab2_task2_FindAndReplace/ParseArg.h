#pragma once
#include <fstream>
#include <optional>
#include <iostream>

struct Args
{
    std::string searchString;
    std::string replaceString;
};

std::optional<Args> ParseArg(int argc, char* argv[], std::string& searchString, std::string& replacement);