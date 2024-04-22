#include "Car.h"
using namespace std;

//������� ����� ��� ���������� �����������
void CarControl::Info(IO& io, CarClass& car)const
{
	io.out << "Is Turned On ";
	if (car.IsTurnedOn())
	{
		io.out << "on";
	}
	else
	{
		io.out << "off";
	}
	io.out << " Speed " << car.GetSpeed()<< " Gear " << car.GetGear() << " Direction " << car.GetDirection()<< endl;
}

bool CarControl::EngineOn(IO& io, CarClass& car)
{
	return car.TurnOnEngine();
}

bool CarControl::EngineOff(IO& io, CarClass& car)
{
	return car.TurnOffEngine();
}

bool CarControl::SetSpeed(IO& io, CarClass& car)
{
	int speed;
	io.in >> speed;
	return car.SetSpeed(speed);
}

bool CarControl::SetGear(IO& io, CarClass& car)
{
	int gear;
	io.in >> gear;
	return car.SetGear(gear);
}

//���� ������� ������ ��� ���� ���������� ��������
//��� �������� ����� ������ �������� ������ �������� ������� ��� �������� 0
//��������� ����������� �������
//�������� �������� �� ������������� ���������

void Driving�ar(IO& io)
{
	CarClass car;
	CarControl controlCar;
	string command;

	while (io.in >> command && command != "...")
	{
		if (command == "Info")
		{
			controlCar.Info(io, car);
		}
		else if (command == "EngineOn" || command == "EngineOff")
		{
			bool engineResult = command == "EngineOn" ? controlCar.EngineOn(io, car) : controlCar.EngineOff(io, car);
			io.out << (engineResult ? "Engine " + command.substr(6) + "ed" : "not Engine " + command.substr(6) + "ed") << endl;
		}
		else if (command == "SetSpeed" || command == "SetGear")
		{
			bool setResult = command == "SetSpeed" ? controlCar.SetSpeed(io, car) : controlCar.SetGear(io, car);
			io.out << (setResult ? "set " + command.substr(3) : "Error incorrect " + command.substr(3)) << endl;
		}
		else
		{
			io.out << "Error unknown command: " << command << endl;
		}
	}
}

bool CarClass::IsTurnedOn() const
{
	//�� ������ this
	return m_engineOn;
}

bool CarClass::TurnOnEngine()
{
	if (m_gear == 0 && m_speed == 0 && !m_engineOn)
	{
		m_engineOn = true;
		return true;
	}
	else if (m_engineOn)
	{
		return true;
	}
	return false;
}

bool CarClass::TurnOffEngine()
{
	if (m_gear == 0 && m_speed == 0 && m_engineOn)
	{
		m_engineOn = false;
		return true;
	}
	else if (!m_engineOn)
	{
		return true;
	}
	return false;
}

bool CarClass::SetSpeed(const int speed) {
	// ���������, ��� ��������� �������
	if (m_engineOn)
	{
		// ��������� �������� �������� � �������� ��������
		if ((m_gear == 0 && abs(m_speed) > abs(speed)) ||
			(m_gear == -1 && speed >= -20 && speed <= 0) ||
			(m_gear == 1 && speed >= 0 && speed <= 30) ||
			(m_gear == 2 && speed >= 20 && speed <= 50) ||
			(m_gear == 3 && speed >= 30 && speed <= 60) ||
			(m_gear == 4 && speed >= 40 && speed <= 90) ||
			(m_gear == 5 && speed >= 50 && speed <= 150)) 
		{
			m_speed = speed;
			return true;
		}
	}
	return false;
}
//���������
bool CarClass::SetGear(const int gear)
{
	if (gear < -1 || gear > 5) // ���������, ��� ���������� �������� gear ��������� � ��������� �� -1 �� 5
	{
		return false;
	}
	//������ ������������ ����
	if (gear == 0 || // ����� ���������� ����������� �������� ������
		(m_engineOn && // ���������, ��� ��������� �������
			(gear == -1 && m_speed == 0) ||
			(gear == 1 && m_speed >= 0 && m_speed <= 30) ||
			(gear == 2 && m_speed >= 20 && m_speed <= 50) ||
			(gear == 3 && m_speed >= 30 && m_speed <= 60) ||
			(gear == 4 && m_speed >= 40 && m_speed <= 90) ||
			(gear == 5 && m_speed >= 50 && m_speed <= 150)))
	{
		m_gear = gear;
		return true;
	}
	return false;
}

string CarClass::GetDirection() const
{
	if (m_speed == 0)
	{
		return "standing still";
	}
	else if (m_speed < 0)
	{
		return "backward";
	}
	else // m_speed > 0
	{
		return "forward";
	}
}

int CarClass::GetSpeed() const
{
	return m_speed;
}

int CarClass::GetGear() const
{
	return m_gear;
}
