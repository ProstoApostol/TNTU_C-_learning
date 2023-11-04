#include "WholesaleBase.h"

WholesaleBase::WholesaleBase(){
	cout << "Enter the number of newspaper in base!" << endl;
	AddNewspaper(List);
	cout << "<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>" << endl;

	cout << "\nEnter the number of newspaper in kiosk1! " << endl;
	AddNewspaper(Kiosk1);
	cout << "<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>" << endl;

	cout << "\nEnter the number of newspaper in kiosk2! " << endl;
	AddNewspaper(Kiosk2);
	cout << "<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>" << endl;

	cout << "\nEnter the number of newspaper in kiosk3! " << endl;
	AddNewspaper(Kiosk3);
	cout << "<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>" << endl;

	cout << "\nEnter the number of newspaper in kiosk4! " << endl;
	AddNewspaper(Kiosk4);
	cout << "<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>" << endl;
}

void WholesaleBase::AddNewspaper(map<int, string>& Other){
	int n;
	cout << "\nEnter the number of newspaper: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++) {
		int id;
		string name;
		cout << "Enter the id of the newspaper: ";
		cin >> id;
		cout << "Enter the name of the newspaper: ";
		cin >> name;
		cout << endl;

		Other.insert(pair<int, string>(id, name));
	}
}

void WholesaleBase::AllPrint(){
	cout << "\n\nAll the data you entered:\n" << endl;
	cout << "\nList of newspapers that are on the List:" << endl;
	Print(List);
	cout << "<-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=->" << endl;

	cout << "\nList of newspapers that are on the kiosk1:" << endl;
	Print(Kiosk1);
	cout << "<-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=->" << endl;

	cout << "\nList of newspapers that are on the kiosk2:" << endl;
	Print(Kiosk2);
	cout << "<-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=->" << endl;

	cout << "\nList of newspapers that are on the kiosk3:" << endl;
	Print(Kiosk3);
	cout << "<-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=->" << endl;

	cout << "\nList of newspapers that are on the kiosk4:" << endl;
	Print(Kiosk4);
	cout << "<-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=->" << endl;
}

void WholesaleBase::SearchTheNewspaper(){
	cout << "\n" << endl;
	map<int, string> Newspapar1; //Newspaper that are available in all kiosks
	map<int, string> Newspapar2; //Newspaper that are available in at least one kiosk
	map<int, string> Newspapar3; //Newspaper that are not available in only one kiosk

	int Check1, Check2, Check3;

	for (auto i = List.begin(); i != List.end(); i++) {
		if (searchTheNewspaper(Kiosk1, i->first) && searchTheNewspaper(Kiosk2, i->first) &&
			searchTheNewspaper(Kiosk3, i->first) && searchTheNewspaper(Kiosk4, i->first)) {
			Newspapar1[i->first] = i->second;
		}
		if (searchTheNewspaper(Kiosk1, i->first) || searchTheNewspaper(Kiosk2, i->first) ||
			searchTheNewspaper(Kiosk3, i->first) || searchTheNewspaper(Kiosk4, i->first)) {
			Newspapar2[i->first] = i->second;
		}
		if ((searchTheNewspaper(Kiosk1, i->first) ? 1 : 0) +
			(searchTheNewspaper(Kiosk2, i->first) ? 1 : 0) +
			(searchTheNewspaper(Kiosk3, i->first) ? 1 : 0) +
			(searchTheNewspaper(Kiosk4, i->first) ? 1 : 0) == 1) {
			Newspapar3[i->first] = i->second;
		}
	}

	cout << "\nList of newspapers that are available in all kiosks:" << endl;
	if (Newspapar1.empty()) {
		cout << "There are no such newspapers!" << endl;
	}
	else {
		Print(Newspapar1);
	}

	cout << "\nList of newspapers that are available in at least one kiosk:" << endl;
	if (Newspapar2.empty()) {
		cout << "There are no such newspapers!" << endl;
	}
	else {
		Print(Newspapar2);
	}

	cout << "\nList of newspapers that are not available in only one kiosk:" << endl;
	if (Newspapar3.empty()) {
		cout << "There are no such newspapers!" << endl;
	}
	else {
		Print(Newspapar3);
	}
}
