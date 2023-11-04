#pragma once
#include <iostream>
#include <set>
#include <string>
using namespace std;

class Shop1 {
private:
    set<string> ProductsReceived;

public:
    Shop1() {
        string Product;

        cout << "Enter products received by the Shop1: " << endl;
        cout << "To stop adding products, enter \"stop\"" << endl;
        do {
            cout << "Enter product: ";
            cin >> Product;

            if (Product != "stop") {
                ProductsReceived.insert(Product);
            }

        } while (Product != "stop");
        cout << endl;
    }

    bool SearchTheProduct(string Product) {
        for (auto element : ProductsReceived) {
            if (element == Product) {
                return true;
            }
        }

        return false;
    }

    friend class WholesaleBase;
};