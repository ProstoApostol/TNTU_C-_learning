#pragma once
#include <iostream>
using namespace std;

class KMP {
private:
    const string pattern;
    int* prefix;

public:

    KMP(const string& pattern) : pattern(pattern) {
        prefix = new int[pattern.length()];
        computePrefixFunction();
    }

    ~KMP() {
        delete[] prefix;
    }

    void computePrefixFunction();

    int findPeriodicity();
};
