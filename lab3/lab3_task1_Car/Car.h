#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct IO {
    std::istream& in;
    std::ostream& out;
};

//������������� � Car
class CarClass {
public:
    //������ �� �������� ��������� �����������!!!!
    bool IsTurnedOn() const;//��������� ���������(������� ��� ��������) 
    string GetDirection() const;//����������� ��������(������, ����� ��� ����� �� �����) � ����� `GetDirection()`
    int GetSpeed() const;//������� �������� ��������(����� ����� �� 0 �� ������������ ��������) � ����� `GetSpeed()
    int GetGear() const;//������� ��������� ��������[-1..5] � ����� `GetGear()`

    bool TurnOnEngine();//��������� 
    bool TurnOffEngine(); //��� ���������� ���������
    bool SetSpeed(const int speed);//
    bool SetGear(const int gear);

private:
    //������������ ������������� �������� �������� ��� ��������� ����������� ��������
    bool m_engineOn = false;//��������� ��������� ��� ����
    int m_gear = 0;//��������
    int m_speed = 0;//��������   
};

class CarControl {
public:
    void Info(IO& io, CarClass& car) const;
    bool EngineOn(IO& io, CarClass& car);
    bool EngineOff(IO& io, CarClass& car);
    bool SetSpeed(IO& io, CarClass& car);
    bool SetGear(IO& io, CarClass& car);
};

void Driving�ar(IO &io);