#pragma once
#include <iostream>
#include <vector>
#include "Fraction.h"	
using namespace std;

class Vector {
private:
	vector<Fraction> Number;
public:
	Vector();

	void MagnificationOfTheVector();

	void CreatingANewVector();

	void Show_vector();

	void Concatenate();
};
