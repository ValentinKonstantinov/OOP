#include "Body.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>

CBody::CBody(const std::string& type, double density)
	: m_density(density)
	, m_type(type)
{
}

CBody::CBody(const std::string& type)
	: m_type(type)
{
}

double CBody::GetDensity()const
{
	return m_density;
}

double CBody::GetMass()const
{
	return GetVolume() * GetDensity();
}

std::string CBody::ToString()const
{
	std::ostringstream strm;
	strm << m_type << ":" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}
