#include "Vector.h"
#include "Fraction.h"
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

Vector::Vector() {
	int number, num, den;

	cout << "Enter the number of fractions: ";
	cin >> number;

	for (int q = 0; q < number; q++) {
		cout << "\nEnter the numerator: ";
		cin >> num;
		cout << "Enter the denominator: ";
		cin >> den;

		Number.push_back(Fraction(num, den));
	}
}

void Vector::MagnificationOfTheVector() {
	int N;
	cout << "\nEnter the number of additional items: ";
	cin >> N;

	try {
		Number.reserve(Number.size() + N);
		for (int i = 0; i < N; ++i) {
			int randomNumerator = rand() % 10;
			int randomDenominator = rand() % 10 + 1;
			Number.emplace_back(randomNumerator, randomDenominator);
		}
	}
	catch (const bad_alloc& e) {
		cerr << "Error: No free memory to increase the vector size." << endl;
	}

	cout << "The operation was successful\n" << endl;
}

void Vector::CreatingANewVector() {
	int number;
	cout << "Enter the number of first items you want to sort: ";

	while (true) {
		cin >> number;
		if (number > Number.size() or number < 0) {
			cout << "\nError!\nEnter the number of first items you want to sort: ";
		}
		else {
			break;
		}
	}

	vector<Fraction> NewNumber(Number.begin(), Number.begin() + number);
	sort(NewNumber.begin(), NewNumber.end());

	for (int q = number; q < Number.size(); q++) {
		NewNumber.push_back(Number[q]);
	}

	Number.clear();

	for (int q = 0; q < NewNumber.size(); q++) {
		Number.push_back(NewNumber[q]);
	}

	NewNumber.clear();
	cout << "The operation was successful\n" << endl;
}

void Vector::Show_vector() {
	cout << "\nYour vector: " << endl;
	for (int q = 0l; q < Number.size(); q++) {
		cout << "vector[" << q << "] = " << Number[q] << endl;
	}
	cout << endl;
}

void Vector::Concatenate() {

	int A, B;
	cout << "Select two items from the array to concatenate: ";
	cin >> A >> B;

	int newNumerator = (Number[A].getNumerator() * Number[B].getDenominator() + Number[B].getNumerator() * Number[A].getDenominator());
	int newDenominator = (Number[A].getNumerator() * Number[B].getDenominator());

	Number.push_back(Fraction(newNumerator, newDenominator));
}
