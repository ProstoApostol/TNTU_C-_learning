#include<iostream>
#include<list>
#include<string>
#include "AviationData.h"
using namespace std;

int main() {
	AviationData data;

	int Choice;
	do{
		cout << "Select a list:\n1 - Adding applications to the list\n2 - deletion of applications\n3 - displaying requests by a given flight number and departure date\n4 - Withdrawal of all orders\n0 - Exit\n";
		cin >> Choice;
		cout << endl;
		
		switch (Choice){
			case 1:
				data.Add();
				break;
			case 2:
				data.Delete();
				break;
			case 3:
				data.WithdrawalOfCertainOrders();
				break;
			case 4:
				data.Show();
				break;
			case 0:
				cout << "Goodbye!\n" << endl;
				break;
		default:
			cout<< "\nError\n" << endl;
		}
	} while (Choice != 0);

}