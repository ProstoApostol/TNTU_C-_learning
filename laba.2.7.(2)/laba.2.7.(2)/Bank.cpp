#include "Bank.h"

Bank::Bank()
{
    string accountNumber;
    cout << "Create an account!" << endl;
    cout << "Enter account number: ";
    cin >> accountNumber;

    accounts.insert(pair<string, Account>(accountNumber, Account(accountNumber)));
    cout << endl;
}

void Bank::CreateAccount()
{
    string accountNumber;
    cout << "Create an account!" << endl;
    cout << endl;

    do {
        cout << "Enter account number: ";
        cin >> accountNumber;

        if (accounts.find(accountNumber) != accounts.end()) {
			cout << "This account already exists!" << endl;
		}
		else {
			break;
		}

    } while (true);

    accounts.insert(pair<string, Account>(accountNumber, Account(accountNumber)));
    cout << endl;
}

void Bank::ChangeOfOwnership()
{
    string accountNumber;
    cout << "Enter the account number of the account you want to change: ";
    cin >> accountNumber;
    cout << endl;

    for (auto i = accounts.begin(); i != accounts.end(); i++) {
        if (accountNumber == i->first) {
            string NewName;
            cout << "Enter new name: ";
            cin >> NewName;

            i->second.ChangeName(NewName);
            break;
        }
    }
    cout << endl;
}

void Bank::WithdrawMoney()
{
    string accountNumber;
    cout << "Enter the account number of the account you want to change: ";
    cin >> accountNumber;
    cout << endl;

    int Number;
    for (auto i = accounts.begin(); i != accounts.end(); i++) {

        if (accountNumber == i->first) {
            do {
                cout << "Enter the amount you want to withdraw: ";
                cin >> Number;
                cout << endl;

                if (Number > (i->second.GetBalance())) {
                    cout << "You don't have enough money on your account!" << endl;
                }
                else {
                    break;
                }

            } while (true);

            i->second.Withdrawal(Number);

        }
    }

    cout << "\nYou have successfully withdrawn money!\n" << endl;
}

void Bank::DepositMoney()
{
    string accountNumber;
    cout << "Enter the account number of the account you want to change: ";
    cin >> accountNumber;
    cout << endl;

    int Number;
    for (auto i = accounts.begin(); i != accounts.end(); i++) {

        if (accountNumber == i->first) {
            cout << "Enter the amount you want to deposit: ";
            cin >> Number;
            cout << endl;

            i->second.Deposit(Number);
        }
    }

    cout << "\nYou have successfully deposited money!\n" << endl;
}

void Bank::CalculateInterest()
{
    string accountNumber;
    cout << "Enter the account number of the account you want to change: ";
    cin >> accountNumber;
    cout << endl;

    for (auto i = accounts.begin(); i != accounts.end(); i++) {

        if (accountNumber == i->first) {
            i->second.AddInterest();
            break;
        }
    }
    cout << "\nInterest accrued!\n" << endl;
}

void Bank::ConversionToDollars()
{
    string accountNumber;
    cout << "Enter the account number of the account you want to change: ";
    cin >> accountNumber;
    cout << endl;

    for (auto i = accounts.begin(); i != accounts.end(); i++) {

        if (accountNumber == i->first) {

            if (i->second.GetCurrency() != "Dollar") {

                if (i->second.GetCurrency() == "Euro") {
                    double balance = i->second.GetBalance();
                    double dollars = balance * 40;
                    dollars = dollars / 38;
                    cout << "\nBalance in dollars: " << dollars << "\n" << endl;
                    i->second.SetCurrency("Dollar");
                    i->second.SetBalance(dollars);
                    break;
                }
                double balance = i->second.GetBalance();
                double dollars = balance / 38;
                cout << "\nBalance in dollars: " << dollars << "\n" << endl;
                i->second.SetCurrency("Dollar");
                i->second.SetBalance(dollars);
                break;
            }
            else {
                cout << "\nThis account is already in dollars!\n" << endl;
            }
        }
    }
}

void Bank::ConversionToEuros()
{
    string accountNumber;
    cout << "Enter the account number of the account you want to change: ";
    cin >> accountNumber;
    cout << endl;

    for (auto i = accounts.begin(); i != accounts.end(); i++) {

        if (accountNumber == i->first) {

            if (i->second.GetCurrency() != "Euro") {

                if (i->second.GetCurrency() == "Dollar") {
                    double balance = i->second.GetBalance();
                    double euros = balance * 38;
                    euros = euros / 40;
                    cout << "\nBalance in euros: " << euros << "\n" << endl;
                    i->second.SetCurrency("Euro");
                    i->second.SetBalance(euros);
                    break;
                }

                double balance = i->second.GetBalance();
                double euros = balance / 40;
                cout << "\nBalance in euros: " << euros << "\n" << endl;
                i->second.SetCurrency("Euro");
                i->second.SetBalance(euros);
                break;
            }
            else {
                cout << "\nThis account is already in euros!\n" << endl;
                break;
            }
        }
    }
}

void Bank::ConversionToHryvnia()
{
    string accountNumber;
    cout << "Enter the account number of the account you want to change: ";
    cin >> accountNumber;
    cout << endl;

    for (auto i = accounts.begin(); i != accounts.end(); i++) {

        if (accountNumber == i->first) {

            if (i->second.GetCurrency() != "Hryvnia") {

                if (i->second.GetCurrency() == "Dollar") {
                    double balance = i->second.GetBalance();
                    double hryvnia = balance * 38;
                    cout << "\nBalance in hryvnia: " << hryvnia << "\n" << endl;
                    i->second.SetCurrency("Hryvnia");
                    i->second.SetBalance(hryvnia);
                    break;
                }
                double balance = i->second.GetBalance();
                double hryvnia = balance * 40;
                cout << "\nBalance in hryvnia: " << hryvnia << "\n" << endl;
                i->second.SetCurrency("Hryvnia");
                i->second.SetBalance(hryvnia);
                break;
            }
            else {
                cout << "\nThis account is already in hryvnia!\n" << endl;
                break;
            }
        }
    }
}

void Bank::Print()
{
    int q = 0;

    for (auto it = accounts.begin(); it != accounts.end(); it++) {
        cout << "\n<------------- Account: " << q + 1 << " ------------->" << endl;
        it->second.Print();
        cout << "<-------------------------------------->\n" << endl;
        q++;
    }
    cout << endl;
}
