#include "Time.h"

Time::Time()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	sec = st.wSecond;
	min = st.wMinute;
	hours = st.wHour;
}
Time::Time(unsigned int sec, unsigned int min, unsigned int hours)
{
	SetSec(sec);
	SetMin(min);
	SetHours(hours);
}

void Time::SetSec(unsigned int sec)
{
	if (sec >= 0 && sec < 60)
	{
		this->sec = sec;
	}
	else
		throw "incorrect value!!!";
}
void Time::SetMin(unsigned int min)
{
	if (min >= 0 && min < 60)
	{
		this->min = min;
	}
	else
		throw "incorrect value!!!";
}
void Time::SetHours(unsigned int hours)
{
	if (hours >= 0 && hours < 24)
	{
		this->hours = hours;
	}
	else
		throw "incorrect value!!!";
}

Time Time::operator+(unsigned short sec)
{
	if (sec == 0) return *this;
	else if (sec != 0)
	{
		if (this->sec > 59)
		{
			this->min++;
			this->sec = 0;
		}
		if (this->min > 59)
		{
			this->hours++;
			this->min = 0;
		}
		if (this->hours > 23)
		{
			this->hours = 0;
		}
	}
}

Time Time::operator-(unsigned short sec)
{
	if (sec == 0) return *this;
	else if (sec != 0)
	{
		if (this->sec > 59)
		{
			this->min--;
			sec--;
		}
		if (this->min > 59)
		{
			this->hours--;
			this->min = 59;
		}
		if (this->hours > 23)
		{
			this->hours = 23;
		}
	}
}


Time& Time::operator++()
{
	sec++;
	if (sec > 59)
	{
		sec++;
		sec = 0;
	}
	if (min > 59)
	{
		min++;
		min = 0;
	}
	if (hours > 23)
	{
		hours = 0;
	}
	return *this;
}
Time& Time::operator++(int value)
{
	Time temp(*this);
	if (sec > 59)
	{
		sec++;
		sec = 0;
	}
	if (min > 59)
	{
		min++;
		min = 0;
	}
	if (hours > 23)
	{
		hours = 0;
	}
	return temp;
}

Time& Time::operator--()
{
	sec--;
	if (sec > 59)
	{
		sec--;
		sec = 0;
	}
	if (min > 59)
	{
		min--;
		min = 0;
	}
	if (hours > 23)
	{
		hours = 0;
	}
	return *this;
}
Time& Time::operator--(int value)
{

	Time temp(*this);
	if (sec > 59)
	{
		sec--;
		sec = 0;
	}
	if (min > 59)
	{
		min--;
		min = 0;
	}
	if (hours > 23)
	{
		hours = 0;
	}
	return temp;
}

bool Time::operator==(Time& time)
{
	return hours == time.hours && min == time.min && sec == time.sec;
}
bool Time::operator!=(Time& time)
{
	return hours != time.hours && min != time.min && sec != time.sec;
}
bool Time::operator>(Time& time)
{
	if (hours < time.hours)
		return true;
	else if (hours > time.hours)
		return false;

	if (min < time.min)
		return true;
	else if (min > time.min)
		return false;

	if (sec < time.sec)
		return true;
	else if (sec > time.sec)
		return false;
	
}
bool Time::operator<(Time& time)
{
	if (hours > time.hours)
		return true;
	else if (hours < time.hours)
		return false;

	if (min > time.min)
		return true;
	else if (min < time.min)
		return false;

	if (sec > time.sec)
		return true;
	else if (sec < time.sec)
		return false;
}

ostream& operator <<(ostream& os, const Time& time)
{
	os << time.hours << ":" << time.min << ":" << time.sec;
	return os;
}
istream& operator >>(istream& is, Time& time)
{
	is >> time.hours >> time.min >> time.sec;
	return is;
}

void Time::Print()
{
	cout << hours << ":" << min << ":" << sec;
}

