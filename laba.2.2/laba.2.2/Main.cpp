#include <iostream>
#include <string>
#include <vector>
#include "Vector.h"
using namespace std;

void While(Vector vector) {
	int method;

	do {
		cout << "\nChoose a method:\n1 - creating a new vector\n2 - increase the size of the vector\n3 - Vector output\n4 - Concatenation of fractions\n0 - Exit\n";
		cin >> method;
		cout << endl;

		if (method == 1) {
			vector.CreatingANewVector();
		}
		else if (method == 2) {
			vector.MagnificationOfTheVector();
		}
		else if (method == 3) {
			vector.Show_vector();
		}
		else if (method == 4) {
			vector.Concatenate();
		}
		else {
			cout << "\nError!\nTry again!\n" << endl;
		}

	} while (method != 0);
}

int main() {
	Vector vector;

	While(vector);

	return 0;
}
