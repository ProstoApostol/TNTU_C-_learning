#include "AviationData.h"

AviationData::AviationData(){
	int Number;
	cout << "Enter the number of applications: ";
	cin >> Number;

	for (int i = 0; i < Number; i++) {
		cout << endl;
		Data temp;
		datas.push_back(temp);
	}
}

void AviationData::Add(){
	cout << "Fill out a new application:" << endl;
	Data temp;
	datas.push_back(temp);
	cout << "Application added!\n" << endl;
}

void AviationData::Delete(){
	int numb;
	cout << "Enter the number of the application you want to delete: ";
	cin >> numb;

	for (auto i = datas.begin(); i != datas.end(); i++) {
		if (numb == 1) {
			datas.erase(i);
			cout << "Application deleted!\n" << endl;
			break;
		}
		numb--;
	}
	cout << "Application from a distance!\n" << endl;

}

void AviationData::WithdrawalOfCertainOrders(){
	string FlightNumber;
	string DesiredDateOfDeparture;

	cout << "Enter the flight number: ";
	cin >> FlightNumber;
	cout << "Enter the date of departure: ";
	cin >> DesiredDateOfDeparture;
	cout << endl;

	int Check = 0, e = 1;
	for (auto i = datas.begin(); i != datas.end(); i++) {

		if (i->GetFlightNumber() == FlightNumber && i->GetDesiredDateOfDeparture() == DesiredDateOfDeparture) {
			cout << "Found applications:\n" << endl;

			cout << "<===== Application number: " << e << " =====>\n" << endl;
			i->Show();
			cout << "\n<=================================>\n" << endl;
			e++;

			for (auto w = i; w != datas.end(); w++) {

				if (w != i) {
					if (w->GetFlightNumber() == FlightNumber && w->GetDesiredDateOfDeparture() == DesiredDateOfDeparture) {
						cout << "<===== Application number: " << e << " =====>\n" << endl;
						w->Show();
						cout << "\n<=================================>\n" << endl;
						e++;
					}
				}
			}

			Check++;
		}
	}
	if (Check == 0) {
		cout << "No applications found!\n" << endl;
	}
}

void AviationData::Show(){
	int w = 1;
	cout << "All applications:\n" << endl;
	for (auto i = datas.begin(); i != datas.end(); i++) {
		cout << "<===== Application number: " << w << " =====>\n" << endl;
		i->Show();
		cout << "\n<=================================>\n" << endl;
		w++;
	}
}
