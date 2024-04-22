#pragma once

void replace(std::ifstream& mask, std::ifstream& replacement, std::ifstream& input, std::ofstream& output);

void —haracter—omparison(char& ch1, char& ch2, int& j, std::string& searchString, std::string& tempStringForReadingSimbols, std::ofstream& output, std::string& replacement);

void replaceLine(char& ch2, std::string& searchString, std::string& line, char& ch1, std::ofstream& output, std::string& replacement, std::ifstream& input);
