#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class RealNumberVector {
private:
    vector<double> Data;

public:
    RealNumberVector();

    void writeToStream();

    void readFromStream();

    void transformAndCheckIncreasing();

    void Show();

};
