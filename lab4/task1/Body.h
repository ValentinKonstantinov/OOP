#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>
//������ ������ ����������
class CBody
{
public:
	CBody(const std::string& type, double density);
	CBody(const std::string& type);
	//density �������� ����� �����
	double GetDensity() const;//���������
	virtual double GetVolume() const = 0;//�����
	double GetMass() const;//�����
	std::string ToString() const;//�������� ���� ������

	virtual ~CBody() = default;

private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	double m_density = 0;//���������
	std::string m_type;//��� ������
};

