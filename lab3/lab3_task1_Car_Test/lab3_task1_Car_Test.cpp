#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../../OOP/Malov-labs/oop/catch2/catch.hpp"
#include "../lab3_task1_Car/Car.h"


SCENARIO("turning on the engine at neutral gear and zero speed")
{
	CarClass car;
	car.TurnOnEngine();
	REQUIRE(car.IsTurnedOn());
	//
}

SCENARIO("engine shutdown at neutral gear and zero speed")
{
	CarClass car;
	car.TurnOnEngine();
	car.TurnOffEngine();;
	REQUIRE(!car.IsTurnedOn());
}

SCENARIO("find out the direction of movement at neutral gear and zero speed")
{
	CarClass car;
	REQUIRE(car.GetDirection() == "standing still");
}

SCENARIO("engage 1st gear and speed 20")
{
	CarClass car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(20);
	REQUIRE(car.GetDirection() == "forward");
	REQUIRE(car.GetSpeed() == 20);
	REQUIRE(car.GetGear() == 1);
}

SCENARIO("engage 2st gear and speed 40")
{
	CarClass car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(20);
	car.SetGear(2);
	car.SetSpeed(50);
	REQUIRE(car.GetDirection() == "forward");
	REQUIRE(car.GetSpeed() == 50);
	REQUIRE(car.GetGear() == 2);
}

SCENARIO("engage 2st gear and speed 40 and brake and turn off")
{
	CarClass car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(20);
	car.SetGear(2);
	car.SetSpeed(50);
	car.SetGear(0);
	car.SetSpeed(0);
	car.TurnOffEngine();
	REQUIRE(!car.IsTurnedOn());
	REQUIRE(car.GetDirection() == "standing still");
	REQUIRE(car.GetSpeed() == 0);
	REQUIRE(car.GetGear() == 0);
}

SCENARIO("engage -1st gear and speed 20 and brake and turn off")
{
	CarClass car;
	car.TurnOnEngine();
	car.SetGear(-1);
	car.SetSpeed(-20);
	REQUIRE(car.IsTurnedOn());
	REQUIRE(car.GetDirection() == "backward");
	REQUIRE(car.GetSpeed() == -20);
	REQUIRE(car.GetGear() == -1);

	REQUIRE(car.SetGear(0));
	REQUIRE(car.SetSpeed(0));
	REQUIRE(car.TurnOffEngine());
	REQUIRE(!car.IsTurnedOn());
	REQUIRE(car.GetDirection() == "standing still");
	REQUIRE(car.GetSpeed() == 0);
	REQUIRE(car.GetGear() == 0);
}

SCENARIO("engage -1st gear and speed 20 and engage 1st gear and speed 20")
{
	CarClass car;
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.SetGear(-1));
	REQUIRE(car.SetSpeed(-20));
	REQUIRE(car.IsTurnedOn());
	REQUIRE(car.GetDirection() == "backward");
	REQUIRE(car.GetSpeed() == -20);
	REQUIRE(car.GetGear() == -1);

	REQUIRE(!car.SetGear(1));
	REQUIRE(!car.SetSpeed(40));
	REQUIRE(!car.TurnOffEngine());
	REQUIRE(car.IsTurnedOn());
}

SCENARIO("engage 1st gear and speed 20 and engage 5st gear and speed 100")
{
	CarClass car;
	//дублирующиеся проверки в тестах выделить в функцию
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.SetGear(1));
	REQUIRE(car.SetSpeed(20));
	REQUIRE(car.IsTurnedOn());
	REQUIRE(car.GetDirection() == "forward");
	REQUIRE(car.GetSpeed() == 20);
	REQUIRE(car.GetGear() == 1);

	REQUIRE(!car.SetGear(5));
	REQUIRE(!car.SetSpeed(150));
	REQUIRE(car.IsTurnedOn());
}

SCENARIO("engage 2st gear and speed 50 and engage 1st gear and speed 0")
{
	CarClass car;
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.SetGear(1));
	REQUIRE(car.SetSpeed(20));
	REQUIRE(car.SetGear(2));
	REQUIRE(car.SetSpeed(50));
	REQUIRE(car.IsTurnedOn());
	REQUIRE(car.GetDirection() == "forward");
	REQUIRE(car.GetSpeed() == 50);
	REQUIRE(car.GetGear() == 2);

	REQUIRE(!car.SetGear(1));
	REQUIRE(!car.SetSpeed(0));
	REQUIRE(!car.TurnOffEngine());
	REQUIRE(car.IsTurnedOn());
}

SCENARIO("управление виртуальным автомобилем")
{
	stringstream input{ "Info\nEngineOn\nSetGear 1\nSetSpeed 20\nInfo\n..." };
	stringstream output;
	IO io{input, output};
	DrivingСar(io);
	REQUIRE(output.str()=="Is Turned On off Speed 0 Gear 0 Direction standing still\nEngine Oned\nset Gear\nset Speed\nIs Turned On on Speed 20 Gear 1 Direction forward\n");
}