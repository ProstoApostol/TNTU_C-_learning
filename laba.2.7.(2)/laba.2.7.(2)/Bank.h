#pragma once
#include <string>
#include <map>
#include <cmath>
#include "Account.h"
using namespace std;

class Bank {
private:
    multimap<string, Account> accounts;
public:

    Bank();

    void CreateAccount();

    void ChangeOfOwnership();

    void WithdrawMoney();

    void DepositMoney();

    void CalculateInterest();

    void ConversionToDollars();

    void ConversionToEuros();

    void ConversionToHryvnia();

    void Print();
};