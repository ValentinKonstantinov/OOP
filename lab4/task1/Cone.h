#pragma once
#include "Body.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>


class CCone final : public CBody
{
public:
	CCone(double density, double radius, double height);//плотность, радиус, высота

	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	double m_radius;
	double m_height;
};
