#include "Fraction.h"

ostream& operator<<(ostream& os, const Fraction& obj) {
	os << obj.numerator << "/" << obj.denominator;
	return os;
}

bool Fraction::operator<(const Fraction& other) const {
	long long left = static_cast<long long>(numerator) * other.denominator;
	long long right = static_cast<long long>(other.numerator) * denominator;
	return left < right;
}
