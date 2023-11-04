#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix() {
    cout << "Enter the size of the matrix!" << endl;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    Data.resize(col);
    for (int i = 0; i < col; i++) {
        Data[i].resize(row);
    }

    int choice;
    do {
        cout << "\nChoose how to record items:\n1 - Manually\n2 - Randomly\n\nYour choice: ";
        cin >> choice;
    } while (choice != 1 && choice != 2);
    cout << endl;

    if (choice == 1) {

        int Value;
        for (int i = 0; i < col; i++) {
            for (int e = 0; e < row; e++) {
                cout << "Enter the value of the element [" << i << "][" << e << "]: ";
                cin >> Value;
                Data[i][e] = Value;
            }
        }

    }
    else {

        for (int i = 0; i < col; i++) {
            for (int e = 0; e < row; e++) {
                Data[i][e] = rand() % 100;
            }
        }
    }
}

void Matrix::writeToStream() {
    ofstream output_file("matrix.txt");

    if (output_file.is_open()) {
        vector<int> NewData;
        for (const auto& row : Data) {
            NewData.insert(NewData.end(), row.begin(), row.end());
        }
        copy(NewData.begin(), NewData.end(), ostream_iterator<int>(output_file, " "));
    }
    else {
        cout << "Error opening file!" << endl;
    }

    cout << "The data is successfully written to the file." << endl;
    output_file.close();
}

void Matrix::readFromStream() {
    ifstream input_file("matrix.txt");

    if (input_file.is_open()) {
        vector<int> NewData;
        copy(istream_iterator<int>(input_file), istream_iterator<int>(), back_inserter(NewData));

        for (size_t rows = 0; rows < Data.size(); ++rows) {
            for (size_t cols = 0; cols < Data[rows].size(); ++cols) {
                Data[rows][cols] = NewData[rows * Data[rows].size() + cols];
            }
        }
    }
    else {
        cout << "Error opening file!" << endl;
    }
    cout << "The data is successfully read from the file." << endl;
    input_file.close();
}

void Matrix::transformAndPrint() {
    for (size_t row = 0; row < Data.size(); ++row) {
        int maxInRow = *std::max_element(Data[row].begin(), Data[row].end());
        for (size_t col = 0; col < Data[row].size(); ++col) {
            if (row == col) {
                Data[row][col] = maxInRow;
            }
        }
    }

    std::cout << "The matrix after conversion:" << std::endl;
    for (const auto& row : Data) {
        for (int value : row) {
            std::cout << value << ' ';
        }
        std::cout << std::endl;
    }
}

void Matrix::Show() {
    for (int i = 0; i < Data.size(); i++) {
        for (int e = 0; e < Data[i].size(); e++) {
            cout << Data[i][e] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
