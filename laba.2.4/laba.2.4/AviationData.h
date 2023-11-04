#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Data.h"
using namespace std; 

class AviationData {
private:
	list<Data> datas;
public:
	AviationData();

	void Add();

	void Delete();

	void WithdrawalOfCertainOrders();

	void Show();
};