#pragma once
#pragma once
#include "Body.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>

class CCylinder final : public CBody
{
public:
	CCylinder(double density, double radius, double height);//плотность, радиус, высота

	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	double m_radius;
	double m_height;
};
