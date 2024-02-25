#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <cassert>
#include <limits>

struct Args
{
    int inputInt;
};

std::optional<Args> ParseArg(int argc, char* argv[]) 
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: flipbyte.exe <INTEGER>\n";
        return std::nullopt;
    };
    Args args{};
    try
    {
        args.inputInt = std::stoi(argv[1]);
    }
    catch(...)
    {
        return std::nullopt;
    }
    if ((args.inputInt >= 0) && (args.inputInt <= 255))
    {
        return args;
    }
    return std::nullopt;
};
//сделать без рекурсии

unsigned char Reverse_bits(uint8_t x)
{
    x = (x & 0b11110000) >> 4 | (x & 0b1111) << 4;
    x = (x & 0b11001100) >> 2 | (x & 0b00110011) << 2;
    x = (x & 0b10101010) >> 1 | (x & 0b01010101) << 1;
    return (x);
};

int main(int argc, char* argv[])
{
    auto args = ParseArg(argc, argv);
    if (!args)
    {//форматирование 
        std::cout << "Error" << std::endl;
        return 1;
    }
    uint8_t a = args->inputInt;
    unsigned rev_a = Reverse_bits(a);
    std::cout << rev_a << "\n";
    return rev_a;
}