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

//переименовать в Car
class CarClass {
public:
    //методы не меняющие состояние константные!!!!
    bool IsTurnedOn() const;//Состояние двигателя(включен или выключен) 
    string GetDirection() const;//Направление движения(вперед, назад или стоим на месте) – метод `GetDirection()`
    int GetSpeed() const;//Текущая скорость движения(целое число от 0 до максимальной скорости) – метод `GetSpeed()
    int GetGear() const;//Текущая выбранная передача[-1..5] – метод `GetGear()`

    bool TurnOnEngine();//включение 
    bool TurnOffEngine(); //или выключение двигателя
    bool SetSpeed(const int speed);//
    bool SetGear(const int gear);

private:
    //использовать отрицательные значения скорости для обратного направления движения
    bool m_engineOn = false;//состояние двигателя вкл выкл
    int m_gear = 0;//передача
    int m_speed = 0;//скорость   
};

class CarControl {
public:
    void Info(IO& io, CarClass& car) const;
    bool EngineOn(IO& io, CarClass& car);
    bool EngineOff(IO& io, CarClass& car);
    bool SetSpeed(IO& io, CarClass& car);
    bool SetGear(IO& io, CarClass& car);
};

void DrivingСar(IO &io);