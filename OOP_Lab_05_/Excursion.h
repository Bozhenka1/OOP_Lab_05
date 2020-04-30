
#pragma once

#include <string>

using namespace std;

class Excursion
{
private:
	string name;
	string data;
	int duration;

	double price;

	double totalPrice = 0;

protected:
	string GidName;

public:

	void SetName(string name) { this->name = name; }
	void SetData(string data) { this->data = data; }
	void SetDuration(int duration) { this->duration = duration; }
	void SetPrice(double price) { this->price = price; }


	string GetName(void) { return name; }
	string GetData(void) { return data; }
	int GetDuration(void) { return duration; }
	double GetPrice(void) { return price; }

	string GetGidName(void) { return GidName; }

	virtual double GitPrice(void) { return totalPrice; };

	void AddSum(double price);
	double GetTotalPrice(void) { return totalPrice; }
};


class WalkingTour : public Excursion
{
private:

	double GidPrice;

public:

	void SetGidName(string name) { this->GidName = name; }
	void SetGidPrice(double price) { this->GidPrice = price; }



	double GetGidPrice(void) { return GidPrice; }

	double GitPrice(void) override;
};


class MixedExcursion :public Excursion
{
private:

	double GidPrice;

	string BusNamber;
	string DriverName;
	double DriverPrice;
	int PedestrianTime;
	int BusTime;

public:

	void SetGidName(string name) { this->GidName = name; }
	void SetGidPrice(double price) { this->GidPrice = price; }
	void SetBusNamber(string numb) { this->BusNamber = numb; }
	void SetDriverName(string name) { this->DriverName = name; }
	void SetDriverPrice(double price) { this->DriverPrice = price; }
	void SetPedestrianTime(int time) { this->PedestrianTime = time; }
	void SetBusTime(int time) { this->BusTime = time; }


	double GetGidPrice(void) { return GidPrice; }
	string GetBusNamber(void) { return BusNamber; }
	string GetDriverName(void) { return DriverName; }
	double GetDriverPrice(void) { return DriverPrice; }
	int GetPedestrianTime(void) { return PedestrianTime; }
	int GetBusTime(void) { return BusTime; }

	double GitPrice(void) override;
};

