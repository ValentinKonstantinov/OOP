#include <iostream>
#include "../TimesDay/Header.h"
#define CATCH_CONFIG_MAIN

#include "../../../Malov-labs/oop/catch2/catch.hpp"

SCENARIO("Creation initialization classes CTime")
{
	CTime time("01:02:03");
	REQUIRE(time.GetTime() == "01:02:03");

	CTime time2;
	time2.SetTime("10:20:30");
	REQUIRE(time2.GetTime() == "10:20:30");

	CTime time3(time2);
	REQUIRE(time3.GetTime() == "10:20:30");

	time2 = time;
	REQUIRE(time2.GetTime() == "01:02:03");

	CTime time4(5, 6, 7);
	REQUIRE(time4.GetHours() == 5);
	REQUIRE(time4.GetMinutes() == 6);
	REQUIRE(time4.GetSeconds() == 7);

	CTime time5(3661);
	REQUIRE(time5.GetHours() == 1);
	REQUIRE(time5.GetMinutes() == 1);
	REQUIRE(time5.GetSeconds() == 1);
	REQUIRE(time5.GetTime(0) == 3661);
}

SCENARIO("assignment classes CTime")
{
	CTime time(1);
	CTime time2(2);
	CTime time3(time2);
	REQUIRE(time3.GetSeconds() == 2);

	time2 = time;
	REQUIRE(time2.GetSeconds() == 1);
}

SCENARIO("operator ++ classes CTime")
{
	CTime time(1);
	++time;
	REQUIRE(time.GetSeconds() == 2);
	REQUIRE(2 == time++.GetSeconds());
	REQUIRE(time.GetSeconds() == 3);
	
	
	CTime time2(59);
	++time2;
	REQUIRE(time2.GetSeconds() == 0);
	REQUIRE(time2.GetMinutes() == 1);
	REQUIRE(time2++.GetSeconds() == 0);
	REQUIRE(time2.GetSeconds() == 1);

	time2.SetTime("00:59:59");
	++time2;
	REQUIRE(time2.GetSeconds() == 0);
	REQUIRE(time2.GetMinutes() == 0);
	REQUIRE(time2.GetHours() == 1);

	time2.SetTime("23:59:59");
	++time2;
	REQUIRE(time2.GetSeconds() == 0);
	REQUIRE(time2.GetMinutes() == 0);
	REQUIRE(time2.GetHours() == 0);
}

SCENARIO("operator -- classes CTime")
{
	CTime time(1);
	--time;
	REQUIRE(time.GetSeconds() == 0);
	REQUIRE(0 == time--.GetSeconds());
	REQUIRE(time.GetSeconds() == 59);


	CTime time2(0);
	--time2;
	REQUIRE(time2.GetSeconds() == 59);
	REQUIRE(time2.GetMinutes() == 59);
	REQUIRE(time2.GetHours() == 23);


	time2.SetTime("00:01:00");
	--time2;
	REQUIRE(time2.GetSeconds() == 59);
	REQUIRE(time2.GetMinutes() == 0);
	REQUIRE(time2.GetHours() == 0);

	time2.SetTime("01:00:00");
	--time2;
	REQUIRE(time2.GetSeconds() == 59);
	REQUIRE(time2.GetMinutes() == 59);
	REQUIRE(time2.GetHours() == 0);
}

SCENARIO("operator + classes CTime")
{
	CTime time(59);
	CTime time2(1);
	CTime time3;
	time3 = time + time2;
	REQUIRE(time3.GetSeconds() == 0);
	REQUIRE(time3.GetMinutes() == 1);
	REQUIRE(time.GetSeconds() == 59);
	time2.SetTime("00:59:00");
	time = time3 + time2;
	REQUIRE(time.GetSeconds() == 0);
	REQUIRE(time.GetMinutes() == 0);
	REQUIRE(time.GetHours() == 1);
	time2.SetTime("23:00:00");
	time3 = time + time2;
	REQUIRE(time3.GetSeconds() == 0);
	REQUIRE(time3.GetMinutes() == 0);
	REQUIRE(time3.GetHours() == 0);
}

SCENARIO("operator - classes CTime")
{
	CTime time(0);
	CTime time2(2);
	CTime time3;
	time3 = time - time2;
	REQUIRE(time3.GetSeconds() == 58);
	REQUIRE(time3.GetMinutes() == 59);
	REQUIRE(time3.GetHours() == 23);
	REQUIRE(time.GetSeconds() == 0);
}

SCENARIO("operator += classes CTime")
{
	CTime time(59);
	CTime time2(1);
	time += time2;
	REQUIRE(time.GetSeconds() == 0);
	REQUIRE(time.GetMinutes() == 1);
	time2.SetTime("00:59:00");
	time += time2;
	REQUIRE(time.GetSeconds() == 0);
	REQUIRE(time.GetMinutes() == 0);
	REQUIRE(time.GetHours() == 1);
	time2.SetTime("23:00:00");
	time += time2;
	REQUIRE(time.GetSeconds() == 0);
	REQUIRE(time.GetMinutes() == 0);
	REQUIRE(time.GetHours() == 0);
}

SCENARIO("operator -= classes CTime")
{
	CTime time(0);
	CTime time2(2);
	time -= time2;
	REQUIRE(time.GetSeconds() == 58);
	REQUIRE(time.GetMinutes() == 59);
	REQUIRE(time.GetHours() == 23);
}

SCENARIO("operator * classes CTime")
{
	CTime time(12*3600);
	CTime time2(2);
	CTime time3;
	time3 = time * 2;
	REQUIRE(time3.GetSeconds() == 0);
	time3 = 3 * time;
	REQUIRE(time3.GetHours() == 12);
	time3 = time * time2;
	REQUIRE(time3.GetSeconds() == 0);
}

SCENARIO("operator / classes CTime")
{
	CTime time(3600);
	CTime time2(2);
	CTime time3;
	time3 = time / 2;
	REQUIRE(time3.GetMinutes() == 30);
	time3 = time / time2;
	REQUIRE(time3.GetMinutes() == 30);
	time3 = time2 / time;
	REQUIRE(time3.GetMinutes() == 0);
}

SCENARIO("operator /= classes CTime")
{
	CTime time(3600);
	CTime time2(2);
	time = time / 2;
	REQUIRE(time.GetMinutes() == 30);
	time = time / time2;
	REQUIRE(time.GetMinutes() == 15);
}

SCENARIO("operator << classes CTime")
{
	CTime time(3600);
	std::ostringstream stream;
	stream << time;
	REQUIRE(stream.str() == "01:00:00");

}

SCENARIO("operator >> classes CTime")
{
	CTime time(3600);
	std::istringstream stream("01:00:00");
	stream >> time;
	REQUIRE(time.GetTime() == "01:00:00");
}

SCENARIO("operators != and == classes CTime")
{
	CTime time(3600);
	CTime time2(2);
	REQUIRE(time == time);
	REQUIRE(!(time == time2));
	REQUIRE(time != time2);
	REQUIRE(!(time != time));
}

SCENARIO("operators <, >, <=, >= classes CTime")
{
	CTime time(3);
	CTime time2(2);
	REQUIRE(time > time2);
	REQUIRE(time2 < time);
	REQUIRE(time >= time);
	REQUIRE(time >= time2);
	REQUIRE(time2 <= time);
}

