#pragma once
#include "Body.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>

class CParallelepiped final : public CBody
{
public:
	CParallelepiped(double density, double width, double height, double depth);//плотность  ширина длина глубина

	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetVolume() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	double m_width;
	double m_height;
	double m_depth;
};