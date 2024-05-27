#include "Cone.h"
#define _USE_MATH_DEFINES
#include <math.h>
CCone::CCone(double density, double radius, double height)
	: CBody("Cone", density)
	, m_radius(radius)
	, m_height(height)
{
}

double CCone::GetBaseRadius() const
{
	return(m_radius);
}
double CCone::GetHeight() const
{
	return(m_height);
}
double CCone::GetVolume()const 
{
	return(1.0 / 3.0) * M_PI * pow(GetBaseRadius(), 2) * GetHeight();
}

void CCone::AppendProperties(std::ostream& strm) const
{
	strm << "\tradius = " << GetBaseRadius() << std::endl;
	strm << "\theight = " << GetHeight() << std::endl;
}
