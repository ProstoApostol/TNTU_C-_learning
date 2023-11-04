#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;

class WholesaleBase{
private:
	map<int, string> List;

	map<int, string> Kiosk1;
	map<int, string> Kiosk2;
	map<int, string> Kiosk3;
	map<int, string> Kiosk4;
public:
	WholesaleBase();

	//���� � ������� ����� ��� ��������� ����
	void AddNewspaper(map <int, string>& Other);

	void AllPrint();

	//���� � ������� ����� ��� ��������� ����
	void Print(map<int, string>& Other) {
		for (auto i = Other.begin(); i != Other.end(); i++) {
			cout << i->first << " " << i->second << endl;
		}
	}

	void SearchTheNewspaper();

	//���� � ������� ����� ��� ��������� ����
	bool searchTheNewspaper(const map<int, string>& Other, int id) {
		for (auto element : Other) {
			if (element.first == id) {
				return true;
			}
		}
		return false;
	}
};

