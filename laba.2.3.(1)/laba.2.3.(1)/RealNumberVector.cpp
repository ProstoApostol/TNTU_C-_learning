#include "RealNumberVector.h"

RealNumberVector::RealNumberVector() {
    int number;
    cout << "Enter the number of elements: ";
    cin >> number;

    int choice;
    do {
        cout << "\nChoose how to record items:\n1 - Manually\n2 - Randomly\n\nYour choice: ";
        cin >> choice;
    } while (choice != 1 && choice != 2);
    cout << endl;

    if (choice == 1) {

        double value;
        for (int i = 0; i < number; i++) {
            cout << "Enter the value of the " << i + 1 << " element: ";
            cin >> value;
            Data.push_back(value);
        }
    }
    else {
        for (int i = 0; i < number; i++) {
            Data.push_back(rand() % 100);
        }
    }
}

void RealNumberVector::writeToStream() {
    ofstream output_file("data.txt");

    if (output_file.is_open()) {
        copy(Data.begin(), Data.end(), ostream_iterator<double>(output_file, " "));
    }
    else {
        cout << "Error opening file!" << endl;
    }
    output_file.close();
}

void RealNumberVector::readFromStream() {

    ifstream input_file("data.txt");
    Data.clear();
    if (input_file.is_open()) {
        copy(istream_iterator<double>(input_file), istream_iterator<double>(), back_inserter(Data));
    }
    else {
        cout << "Error opening file!" << endl;
    }
    input_file.close();
}

void RealNumberVector::transformAndCheckIncreasing() {
    // Перевіряємо, чи утворюють елементи зростаючу послідовність
    bool isIncreasing = is_sorted(Data.begin(), Data.end());

    if (isIncreasing) {
        cout << "The elements form a growing sequence." << endl;
    }
    else {
        cout << "The elements do not form an increasing sequence." << endl;
    }
}

void RealNumberVector::Show() {
    for (int i = 0; i < Data.size(); i++) {
        cout << Data[i] << " ";
    }
    cout << "\n" << endl;
}
