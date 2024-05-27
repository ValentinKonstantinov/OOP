#pragma once
#include "Body.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>

class CSphere final : public CBody
{
public:
	CSphere(double density, double radius);//плотность и радиус

	double GetRadius() const;
	double GetVolume() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	double m_radius;
};
