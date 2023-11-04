#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {

    Matrix matrix;
    cout << "Matrix:" << endl;
    matrix.Show();

    matrix.writeToStream();

    matrix.readFromStream();

    cout << "\nThe initial matrix : " << std::endl;
    matrix.Show();

    matrix.transformAndPrint();

    return 0;
}
