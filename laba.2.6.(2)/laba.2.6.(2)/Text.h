#pragma once
#include<iostream>
#include<string>
#include<set>
using namespace std;

class Text{
private:
    string text;
    set<char> vowels;
    set<char> consonants;

public:
    Text();

    void print() {
        cout << "Text: " << text << endl;
    }

    void Search();
};

