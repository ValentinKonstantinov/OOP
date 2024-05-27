#pragma once
#include <string>
#include <sstream>
#include <iomanip>
class CTime
{
public:
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);
	CTime(unsigned timeStamp = 0);
	CTime(const std::string& string);
	CTime(const CTime& other) : m_seconds(other.m_seconds) {}

	void SetTime(const std::string& string);
	std::string GetTime()const;
	unsigned GetHours()const;
	unsigned GetMinutes()const;
	unsigned GetSeconds()const;
	unsigned GetTime(int)const;
	CTime& operator++();
	CTime operator++(int);

	CTime& operator--();
	CTime operator--(int);

	CTime operator+(const CTime& other) const;
	CTime operator-(const CTime& other) const;

	CTime& operator+=(const CTime& other);
	CTime& operator-=(const CTime& other);

	CTime operator*(const unsigned factor) const;
	CTime operator*(const CTime& other) const;

	CTime operator/(const unsigned factor) const;
	CTime operator/(const CTime& other) const;

	CTime& operator/=(const unsigned factor);
	CTime& operator/=(const CTime& other);

	friend std::ostream& operator<<(std::ostream& os, const CTime& time);
	friend std::istream& operator>>(std::istream& is, CTime& time);
	friend bool operator==(const CTime& time1, const CTime& time2);
	friend bool operator!=(const CTime& time1, const CTime& time2);
	friend bool operator<(const CTime & time1, const CTime & time2);
	friend bool operator>(const CTime& time1, const CTime& time2);
	friend bool operator<=(const CTime& time1, const CTime& time2);
	friend bool operator>=(const CTime& time1, const CTime& time2);

private:
	bool isValid(unsigned hours, unsigned minutes, unsigned seconds) const;
	bool isValid(unsigned seconds) const;
	bool isValid() const;
	unsigned getSecondsFromString(const std::string& string);
	unsigned m_seconds = 0;
};