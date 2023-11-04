#include <iostream>
#include <vector>
#include "RealNumberVector.h"
using namespace std;

int main() {

    RealNumberVector vector;
    cout << "\nVector elements that we will check for growth: " << endl;
    vector.Show();

    vector.writeToStream();

    vector.readFromStream();

    vector.transformAndCheckIncreasing();

    return 0;
}

