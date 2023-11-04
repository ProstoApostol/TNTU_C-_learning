#pragma once
#include <iostream>
#include <string>
using namespace std;

class Movie{
private:
	string NameMovie;
	int Year;

public:
	Movie() {
		cout << endl;
		cout << "Enter the name of the movie: ";
		cin.ignore();
		getline(cin, NameMovie);
		cout << "Enter the year of the movie: ";
		cin >> Year;
		cout << endl;
	}

	void Print() {
		cout << endl;
		cout << "Name of the movie: " << NameMovie << endl;
		cout << "Year of the movie: " << Year << endl;
		cout << endl;
	}
};

