#include <iostream>
#include <string>
#include "KMP.h"
using namespace std;

int main() {
    string s;

    while (cin >> s) {
        KMP kmp(s);
        int periodicity = kmp.findPeriodicity();
        cout << periodicity << endl;
    }

    return 0;
}
