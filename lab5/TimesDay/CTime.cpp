#include "CTime.h"

CTime::CTime(const std::string& string)
{
	m_seconds = getSecondsFromString(string);
}
CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	if (!isValid(hours, minutes, seconds))
	{
		throw std::invalid_argument("Invalid time: ");
	}
	m_seconds = hours * 3600 + minutes * 60 + seconds;
}
CTime::CTime(unsigned timeStamp)
{
	if (!isValid(timeStamp))
	{
		throw std::invalid_argument("Invalid time: ");
	}
	m_seconds = timeStamp;
}

void CTime::SetTime(const std::string& string)
{
	m_seconds = getSecondsFromString(string);
}
std::string CTime::GetTime() const
{
	std::stringstream ss;
	ss << std::setw(2) << std::setfill('0') << GetHours() << ":";
	ss << std::setw(2) << std::setfill('0') << GetMinutes() << ":";
	ss << std::setw(2) << std::setfill('0') << GetSeconds();
	return ss.str();
}
unsigned CTime::GetTime(int) const
{
	return m_seconds;
}
unsigned CTime::GetHours() const
{
	return m_seconds / 3600;
}
unsigned CTime::GetMinutes() const
{
	return m_seconds % 3600 / 60;
}
unsigned CTime::GetSeconds() const
{
	return m_seconds % 60;
}

CTime& CTime::operator++()
{
	if (m_seconds > 23 * 60 * 60 + 59 * 60 + 58)
	{
		m_seconds = 0;
	}
	else
	{
		m_seconds = ++m_seconds;
	}
	return *this;
}
CTime CTime::operator++(int) {
	CTime temp(*this);
	++(*this);
	return temp;
}

CTime& CTime::operator--()
{
	if (m_seconds == 0)
	{
		m_seconds = 23*3600 + 59*60 + 59;
	}
	else 
	{
		m_seconds = --m_seconds;
	}
	return *this;
}
CTime CTime::operator--(int) {
	CTime temp(*this);
	--(*this);
	return temp;
}

CTime CTime::operator+(const CTime& other) const
{
	CTime result(*this); 
	result.m_seconds += other.m_seconds; 
	if (result.m_seconds >= 24 * 60 * 60)
	{
		result.m_seconds %= (24 * 60 * 60);
	}
	return result;
}
CTime CTime::operator-(const CTime& other) const
{
	CTime result(*this);
	if (result.m_seconds >= other.m_seconds)
	{
		result.m_seconds -= other.m_seconds;
	}
	else
	{
		result.m_seconds = result.m_seconds + 24 * 3600 - other.m_seconds;
	}
	return result;
}

CTime& CTime::operator+=(const CTime& other)
{
	m_seconds += other.m_seconds;
	if (m_seconds >= 24 * 60 * 60)
	{
		m_seconds %= (24 * 60 * 60);
	}
	return *this;
}
CTime& CTime::operator-=(const CTime& other)
{

	if (m_seconds >= other.m_seconds)
	{
		m_seconds -= other.m_seconds;
	}
	else
	{
		m_seconds = m_seconds + 24 * 3600 - other.m_seconds;
	}
	return *this;
}

CTime CTime::operator*(const unsigned factor) const
{
	CTime result(*this);
	result.m_seconds *= factor;
	if (result.m_seconds >= 24 * 60 * 60)
	{
		result.m_seconds %= (24 * 60 * 60);
	}
	return result;
}
CTime CTime::operator*(const CTime& other) const
{
	CTime result(*this);
	result.m_seconds *= other.m_seconds;
	if (result.m_seconds >= 24 * 60 * 60)
	{
		result.m_seconds %= (24 * 60 * 60);
	}
	return result;
}
CTime operator*(const int factor, const CTime& time)
{
	unsigned temp = time.GetTime(0);
	temp *= factor;

	if (temp >= 24 * 60 * 60)
	{
		temp %= (24 * 60 * 60);
	}
	CTime result(temp);
	return result; 
}

CTime CTime::operator/(const unsigned factor) const
{
	CTime result(*this);
	result.m_seconds /= factor;
	if (result.m_seconds >= 24 * 60 * 60)
	{
		result.m_seconds %= (24 * 60 * 60);
	}
	return result;
}
CTime CTime::operator/(const CTime& other) const
{
	CTime result(*this);
	result.m_seconds /= other.m_seconds;
	if (result.m_seconds >= 24 * 60 * 60)
	{
		result.m_seconds %= (24 * 60 * 60);
	}
	return result;
}

CTime& CTime::operator/=(const unsigned factor) 
{
	
	m_seconds /= factor;
	if (m_seconds >= 24 * 60 * 60)
	{
		m_seconds %= (24 * 60 * 60);
	}
	return *this;
}
CTime& CTime::operator/=(const CTime& other) 
{
	m_seconds /= other.m_seconds;
	if (m_seconds >= 24 * 60 * 60)
	{
		m_seconds %= (24 * 60 * 60);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const CTime& time)
{
	if (time.isValid()) {
		unsigned hours = time.m_seconds / 3600;
		unsigned minutes = (time.m_seconds % 3600) / 60;
		unsigned seconds = time.m_seconds % 60;
		os << std::setw(2) << std::setfill('0') << hours << ":"
		<< std::setw(2) << std::setfill('0') << minutes << ":"
		<< std::setw(2) << std::setfill('0') << seconds;
	}
	else {
		os << "INVALID";
	}
	return os;
}
std::istream& operator>>(std::istream& is, CTime& time)
{
	std::string string;
	is >> string;
	time.m_seconds = time.getSecondsFromString(string);

	return is;
}

bool operator==(const CTime& time1, const CTime& time2)
{
	if (time1.m_seconds == time2.m_seconds)
	{
		return true;
	}
	return false;
}
bool operator!=(const CTime& time1, const CTime& time2)
{
	if (time1.m_seconds != time2.m_seconds)
	{
		return true;
	}
	return false;
}
bool operator<(const CTime& time1, const CTime& time2)
{
	if (time1.m_seconds < time2.m_seconds)
	{
		return true;
	}
	return false;
}
bool operator>(const CTime& time1, const CTime& time2)
{
	if (time1.m_seconds > time2.m_seconds)
	{
		return true;
	}
	return false;
}
bool operator<=(const CTime& time1, const CTime& time2)
{
	if (time1.m_seconds <= time2.m_seconds)
	{
		return true;
	}
	return false;
}
bool operator>=(const CTime& time1, const CTime& time2)
{
	if (time1.m_seconds >= time2.m_seconds)
	{
		return true;
	}
	return false;
}


bool CTime::isValid(unsigned hours, unsigned minutes, unsigned seconds)const
{
	if (hours > 23 || minutes > 59 || seconds > 59)
	{
		return false;
	}
	return true;
}
bool CTime::isValid(unsigned seconds)const
{
	if (!(seconds < 86400))
	{
		return false;
	}
	return true;
}
bool CTime::isValid()const
{
	if (!(m_seconds < 86400))
	{
		return false;
	}
	return true;
}

unsigned CTime::getSecondsFromString(const std::string& string)
{
	std::stringstream ss(string);
	unsigned second = 0;
	unsigned hours = 0; 
	unsigned minutes = 0;
	unsigned seconds = 0;
	char simbol;
	if (!(ss >> hours) || !(ss >> simbol) || !(simbol == ':') || !(ss >> minutes) || !(ss >> simbol) || !(simbol == ':') || !(ss >> seconds))
	{
		throw std::invalid_argument("Invalid time string: " + string);
	}
	if (!isValid(hours, minutes, seconds))
	{
		throw std::invalid_argument("Invalid numbers");
	}
	return m_seconds = hours * 3600 + minutes * 60 + seconds;
}


