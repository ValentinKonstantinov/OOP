#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>
//убрать лишние библиотеки
class CBody
{
public:
	CBody(const std::string& type, double density);
	CBody(const std::string& type);
	//density получаем через класс
	double GetDensity() const;//плотность
	virtual double GetVolume() const = 0;//объем
	double GetMass() const;//масса
	std::string ToString() const;//название типа фигуры

	virtual ~CBody() = default;

private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	double m_density = 0;//плотность
	std::string m_type;//тип фигуры
};

