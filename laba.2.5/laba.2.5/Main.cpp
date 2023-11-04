#include<iostream>
#include<string>
#include<deque>
#include"Cinema.h"
using namespace std;

int main() {
	Cinema cinema;

	Cinema cinema2(cinema);

	int Method,Check = 0;
	do {
		cout << "1 - View container\n2 - Modify the container\n3 - View a container using iterators\n4 - Create a second container\n5 - Change the first container and add elements of the second container\n6 - View the first and second containers\nEnter the method of sorting: ";
		cin >> Method;
		cout << endl;
		
		switch(Method) {
		case 1:
			cinema.Print();
			break;
		case 2:
			cinema.ModifyTheContainer();
			break;
		case 3:
			cinema.PrintIterator();
			break;
		case 4:
			cinema2.Replase();
			cout << "The second container was created!\n" << endl;
			Check++;
			break;
		case 5:
			if (Check != 0) {
				cinema.Change_the_first_container_and_add_elements_of_the_second_container(cinema2);
			}
			else {
				cout << "No second container created!\n" << endl;
			}
			break;
		case 6:
			if (Check != 0) {
				cout << "First container: " << endl;
				cinema.Print();
				cout << "\nSecond container: " << endl;
				cinema2.Print();
			}
			else {
				cout << "No second container created!\n" << endl;
			}
			break;
		default:
			cout<< "Error! Invalid method!" << endl;	
		}
	} while (Method != 0);

	return 0;
}