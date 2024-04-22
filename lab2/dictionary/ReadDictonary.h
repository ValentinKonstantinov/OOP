#pragma once
#include <iostream>
#include <fstream>
#include <optional>
#include <map>
using Dictionary = std::map<std::string, std::string>;

bool ReadDictonary(std::string const& dictonaryFileDirrectory, Dictionary& dictonary);