#include "KMP.h"

void KMP::computePrefixFunction() {
    prefix[0] = 0;
    int j = 0;

    for (int i = 1; i < pattern.length(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        prefix[i] = j;
    }
}

int KMP::findPeriodicity() {
    int lastValue = prefix[pattern.length() - 1];
    if (lastValue > 0 && pattern.length() % (pattern.length() - lastValue) == 0) {
        return pattern.length() / (pattern.length() - lastValue);
    }
    else {
        return 1;
    }
}
