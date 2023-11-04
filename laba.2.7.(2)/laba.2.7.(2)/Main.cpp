#include <iostream>
#include "Bank.h"
using namespace std;

class  {

};

int main() {
    Bank account;
    account.Print();

    int Method;

    do {
        cout << "Choose a method:\n1 - Opening a new account\n2 - change the account owner\n3 - withdraw a certain amount of money from the account\n4 - deposit money to the account\n5 - calculate interest\n6 - convert the amount into dollars\n7 - convert the amount into euros\n8 - Convert the amount to UAH\n9 - Display data\nYour choice: ";
        cin >> Method;
        cout << endl;

        switch (Method) {
        case 1:
            account.CreateAccount();
            break;
        case 2:
            account.ChangeOfOwnership();
			break;
        case 3:
			account.WithdrawMoney();
			break;
        case 4:
            account.DepositMoney();
            break;
        case 5:
            account.CalculateInterest();
            break;
        case 6:
            account.ConversionToDollars();
			break;
        case 7:
            account.ConversionToEuros();
            break;
        case 8:
			account.ConversionToHryvnia();
			break;
        case 9:
			account.Print();
            break;
        }
        
			
    } while (Method != 0);
    return 0;
}