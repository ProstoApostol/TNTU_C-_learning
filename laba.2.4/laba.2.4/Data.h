#pragma once
#include <iostream>
#include <string>
using namespace std;

class Data {
private:
	string Destination;
	string FlightNumber;
	string PassengerName;
	string DesiredDateOfDeparture;
public:

	Data();

	string GetFlightNumber() {
		return FlightNumber;
	}

	string GetDesiredDateOfDeparture() {
		return DesiredDateOfDeparture;
	}

	void Show();
};