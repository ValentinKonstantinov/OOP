#pragma once
#include <iostream>
#include <fstream>
#include <optional>
#include <map>
#include <Windows.h>
#include "ParseArg.h"
#include "ReadDictonary.h"
using Dictionary = std::map<std::string, std::string>;
struct IO {
    std::istream& in;
    std::ostream& out;
};

void WorkingWithDictionary(Dictionary& dictonary, IO& io);
bool SaveDictionary(Dictionary const& dictonary, std::string const& dictonaryFilePath);
bool DictionaryWorking(int argc, char* argv[]);
void AddWord(std::string const& word, IO& io, Dictionary& dictonary);