#include <iostream>
#include <string>
#include <set>
#include "Text.h"   
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    Text text;

    text.print();

    text.Search();

    return 0;
}
