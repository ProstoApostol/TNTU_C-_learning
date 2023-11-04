#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account{
private:
    string Name;
    string accountNumber;
    double interestRate;
    double balance;
    string Currency;
public:

    Account(string accountNumber) {
        cout<<"Enter Name: ";
        cin >> Name;
        this->accountNumber = accountNumber;
        cout << "Enter interest rate: ";
        cin >> interestRate;
        cout << "Enter balance: ";
        cin >> balance;
        Currency = "Hryvnia";
    }

    string GetCurrency() {
		return Currency;
	}

    void SetCurrency(string Currency) {
        this->Currency = Currency;
    }

    double GetBalance() {
		return balance;
	}

    double GetInterestRate() {
        return interestRate;
    }

    void ChangeName(string NewName) {
        Name = NewName;
    }

    void Withdrawal(double Number) {
		balance -= Number;
	}

    void Deposit(double Number) {
        balance += Number;
    }

    void AddInterest() {
		balance += balance * interestRate / 100;
	}

    void SetBalance(double balance) {
		this->balance = balance;
	}

    void Print() {
        cout << "Name: " << Name << endl;
        cout << "Account number: " << accountNumber << endl;
        cout << "Interest rate: " << interestRate << endl;
        cout << "Balance: " << balance << endl;
        cout << "Currency: " << Currency << endl;
    }
};

