#pragma once
#include <ostream>
using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;
public:
	Fraction(int num, int denom) :numerator(num), denominator(denom) {};

	friend ostream& operator << (ostream& os, const Fraction& obj);

	bool operator<(const Fraction& other) const;

	int getNumerator() const {
		return numerator;
	}

	int getDenominator() const {
		return denominator;
	}

};
