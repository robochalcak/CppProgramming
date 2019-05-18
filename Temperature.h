#pragma once
#ifndef  TEMPERATURE_H
#define TEMPERATURE_H

class Temperature
{
private:
	double temp;

public:
	Temperature()
	{
		temp = 0.0;
	}

	~Temperature(){}

	Temperature(double te)
	{
		temp = te;
	}

	void setTemperature(double te)
	{
		temp = te;
	}

	double getTemperature()const
	{
		return temp;
	}

	bool isEthylFreezing()const
	{
		if (temp <= -173)
			return true;
		else
			return false;
	}
	
	bool isEthylBoiling()const
	{
		if (temp >= 172)
			return true;
		else
			return false;
	}

	bool isOxygenFreezing()const
	{
		if (temp <= -362)
			return true;
		else
			return false;
	}

	bool isOxygenBoiling()const
	{
		if (temp >= -306)
			return true;
		else
			return false;
	}

	bool isWaterFreezing()const
	{
		if (temp <= 32)
			return true;
		else
			return false;
	}

	bool isWaterBoiling()const
	{
		if (temp >= 172)
			return false;
		else
			return true;
	}

};
#endif // ! TEMPERATURE_H
