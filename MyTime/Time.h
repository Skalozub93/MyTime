#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Time
{
private:
	unsigned int sec;
	unsigned int min;
	unsigned int hours;
public:
	Time();
	Time(unsigned int sec, unsigned int min, unsigned int hours);

	void SetSec(unsigned int sec);
	void SetMin(unsigned int min);
	void SetHours(unsigned int hours);

	Time operator +(unsigned short sec);
	Time operator -(unsigned short sec);

	Time& operator ++();
	Time& operator ++(int value);
	Time& operator --();
	Time& operator --(int value);

	bool operator ==(Time& time);
    bool operator !=(Time& time);
	bool operator >(Time& time);
    bool operator <(Time& time);

	friend ostream& operator <<(ostream& os, const Time& time);
	friend istream& operator >>(istream& is, Time& time);
	void Print();
};

