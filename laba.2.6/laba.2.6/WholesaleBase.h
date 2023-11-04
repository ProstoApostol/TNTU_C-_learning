#pragma once
#include <iostream>
#include <set>
#include <string>
#include "Shop4.h"
#include "Shop3.h"
#include "Shop2.h"
#include "Shop1.h"
using namespace std;

class WholesaleBase {
private:
    set<string> ProductList;

public:
    WholesaleBase() {
        int Method;

        do {
            cout << "Choose method of adding products to the list: " << endl;
            cout << "1. Add products manually" << endl;
            cout << "2. Add products automatically" << endl;
            cin >> Method;

        } while (Method != 1 && Method != 2);

        if (Method == 1) {
            string Product;
            cout << "Enter products to the list: " << endl;
            cout << "To stop adding products, enter \"stop\"" << endl;
            do {
                cout << "Enter product: ";
                cin >> Product;

                if (Product != "stop") {
                    ProductList.insert(Product);
                }
            } while (Product != "stop");
        }
        else if (Method == 2) {
            string products[] = { "Milk", "Bread", "Cheese", "Meat", "Fish", "Vegetables", "Fruits", "Sweets", "Drinks", "Cigarettes" };

            for (int i = 0; i < 10; i++) {
                ProductList.insert(products[i]);
            }
        }
    }

    void SearchTheProducts() {
        set<string> Product1; // Products that are available in all stores
        set<string> Product2; // Products that are available in at least two stores
        set<string> Product3; // Products that are not available in any of the stores

        Shop1 shop1;
        Shop2 shop2;
        Shop3 shop3;
        Shop4 shop4;

        int Check1, Check2, Check3;

        for (auto element : ProductList) {
            Check1 = 0, Check2 = 0, Check3 = 0;

            if (shop1.SearchTheProduct(element)) {
                Check1++;
                Check2++;
            }
            else {
                Check3++;
            }

            if (shop2.SearchTheProduct(element)) {
                Check1++;
                Check2++;
            }
            else {
                Check3++;
            }

            if (shop3.SearchTheProduct(element)) {
                Check1++;
                Check2++;
            }
            else {
                Check3++;
            }

            if (shop4.SearchTheProduct(element)) {
                Check1++;
                Check2++;
            }
            else {
                Check3++;
            }

            if (Check1 == 4) {
                Product1.insert(element);
            }
            else if (Check2 >= 2) {
                Product2.insert(element);
            }
            else if (Check3 == 4) {
                Product3.insert(element);
            }
        }

        cout << "\nProducts that are available in all stores: " << endl;
        if (Product1.empty()) {
            cout << "There are no such products" << endl;
        }
        else {
            for (auto element : Product1) {
                cout << element << endl;
            }
        }
        cout << endl;

        cout << "\nProducts that are available in at least two stores: " << endl;
        if (Product2.empty()) {
            cout << "There are no such products" << endl;
        }
        else {
            for (auto element : Product2) {
                cout << element << endl;
            }
        }
        cout << endl;

        cout << "\nProducts that are not available in any of the stores: " << endl;
        if (Product3.empty()) {
            cout << "There are no such products" << endl;
        }
        else {
            for (auto element : Product3) {
                cout << element << endl;
            }
        }
        cout << endl;

    }

    void Print() {
        cout << "\nProduct list: " << endl;
        for (auto element : ProductList) {
            cout << element << endl;
        }
        cout << endl;
    }
};