#include <iostream>
#include "Header.h"
#include <memory>
#include <vector>

int main()
{
    IO io{ std::cin, std::cout };
    
    std::vector<std::shared_ptr<CBody>> bodies = AddBody(io);

    PrintBodies(io, bodies);

    PrintBodyMaxMass(io, bodies);
    PrintMinimumWeightWater(io, bodies);

}

