#include <iostream>
#include "../task1/Body.h"
#include "../task1/Sphere.h"
#include "../task1/Parallelepiped.h"
#include "../task1/Cone.h"
#define CATCH_CONFIG_MAIN

#include "../../../Malov-labs/oop/catch2/catch.hpp"

SCENARIO("Creation class sphere")
{
	CSphere sphere(1, 1);
	REQUIRE(sphere.GetRadius() == 1);
	REQUIRE((int)sphere.GetVolume() == 4);
	REQUIRE((int)sphere.GetMass() == 4);
	REQUIRE(sphere.ToString() == "Sphere:\n\tdensity = 1\n\tvolume = 4.188790205\n\tmass = 4.188790205\n\tradius = 1\n");
}

SCENARIO("Creation class parallelepiped")
{
	CParallelepiped parallelepiped(1, 1, 1, 1);
	REQUIRE((int)parallelepiped.GetVolume() == 1);
	REQUIRE((int)parallelepiped.GetMass() == 1);
	REQUIRE((int)parallelepiped.GetDensity() == 1);
	REQUIRE(parallelepiped.ToString() == "Parallelepiped:\n\tdensity = 1\n\tvolume = 1\n\tmass = 1\n\twidth = 1\n\theight = 1\n\tdepth = 1\n");
}

SCENARIO("Creation class cone")
{
	CCone cone(1, 1, 1);
	REQUIRE((int)cone.GetVolume() == 1);
	REQUIRE((int)cone.GetMass() == 1);
	REQUIRE((int)cone.GetDensity() == 1);
}

SCENARIO("Creation class cylinder")
{
	CCone cone(1, 1, 1);
	REQUIRE((int)cone.GetVolume() == 1);
	REQUIRE((int)cone.GetMass() == 1);
	REQUIRE((int)cone.GetDensity() == 1);
}