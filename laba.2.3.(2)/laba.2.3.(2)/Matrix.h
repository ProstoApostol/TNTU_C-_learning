#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

class Matrix {
private:
    int col, row;
    vector<vector<int>> Data;

public:
    Matrix();

    void writeToStream();

    void readFromStream();

    void transformAndPrint();

    void Show();

};