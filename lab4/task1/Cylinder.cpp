#include "Cylinder.h"

#define _USE_MATH_DEFINES
#include <math.h>

CCylinder::CCylinder(double density, double radius, double height)
	: CBody("Cylinder", density)
	, m_radius(radius)
	, m_height(height)
{
}

double CCylinder::GetBaseRadius() const
{
	return(m_radius);
}
double CCylinder::GetHeight() const
{
	return(m_height);
}
double CCylinder::GetVolume()const
{
	return M_PI * pow(GetBaseRadius(), 2) * GetHeight();
}

void CCylinder::AppendProperties(std::ostream& strm) const
{
	strm << "\tradius = " << GetBaseRadius() << std::endl;
	strm << "\theight = " << GetHeight() << std::endl;
}
