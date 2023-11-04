#include "Data.h"

Data::Data(){
	cout << "Enter Destination: ";
	cin >> Destination;
	cout << "Enter FlightNumber: ";
	cin >> FlightNumber;
	cout << "Enter PassengerName: ";
	cin >> PassengerName;
	cout << "Enter DesiredDateOfDeparture: ";
	cin >> DesiredDateOfDeparture;
	cout << endl;
}

void Data::Show(){
	cout << "Destination: " << Destination << endl;
	cout << "FlightNumber: " << FlightNumber << endl;
	cout << "PassengerName: " << PassengerName << endl;
	cout << "DesiredDateOfDeparture: " << DesiredDateOfDeparture << endl;
}
