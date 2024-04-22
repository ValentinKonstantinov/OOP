#include <iostream>
#include "Car.h"
//не реализованы исключения у методов класса
int main()
{
	IO io{ std::cin, std::cout };
	DrivingСar(io);
	return 0;
}
