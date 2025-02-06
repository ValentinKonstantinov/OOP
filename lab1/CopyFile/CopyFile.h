#pragma once

void CopyStream(std::ifstream& input, std::ofstream& output);

struct Args {
    std::string inputFileName;
    std::string outputFileName;
};
std::optional<Args> parseArg(int argc, char* argv[]);
