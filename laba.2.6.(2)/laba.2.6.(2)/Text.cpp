#include "Text.h"

Text::Text()
{
    int Method;

    do {
        cout << "Choose method of adding products to the list: " << endl;
        cout << "1. Add products manually" << endl;
        cout << "2. Add products automatically" << endl;
        cin >> Method;

    } while (Method != 1 && Method != 2);

    if (Method == 1) {
        cout << "Enter the Text:" << endl;
        cin.ignore();
        getline(cin, text);
    }
    else if (Method == 2) {
        this->text = "Сонце світить, пташки співають, небо ясне, день чудовий";
    }

    for (char letter : "аеиіоу") {
        vowels.insert(letter);
    }

    for (char letter : "пткфсхцчшщ") {
        consonants.insert(letter);
    }
}

void Text::Search()
{
    set<char> VowelsFound;
    set<char> ConsonantsFound;
    set<char> word;
    int Check = 0;

    for (int q = 0; q < text.length(); q++) {
        for (int w = q; w < text.length(); w++) {
            if (text[w] != ' ' && text[w] != ',' && text[w] != '.' && text[w] != '!' && text[w] != '?') {
                word.insert(text[w]);
            }
            else {
                break;
            }
        }

        // Looks for vowel letters
        if (Check == 0) {
            for (auto e = word.begin(); e != word.end(); e++) {
                for (auto i = vowels.begin(); i != vowels.end(); i++) {
                    if (*e == *i) {
                        VowelsFound.insert(*i);
                    }
                }
            }
        }
        else {
            if (VowelsFound.size() == 0) {
                break;
            }
            else {
                for (auto i = VowelsFound.begin(); i != VowelsFound.end();) {
                    int Check2 = 0;
                    for (auto e = word.begin(); e != word.end(); e++) {
                        if (*i == *e) {
                            Check2++;
                        }
                    }
                    if (Check2 == 0) {
                        auto toErase = i;
                        ++i;
                        VowelsFound.erase(toErase);
                    }
                    else {
                        ++i;
                    }
                }
            }
        }

        // Looks for consonant letters
        for (auto i = consonants.begin(); i != consonants.end(); i++) {
            int Check2 = 0;
            for (auto e = word.begin(); e != word.end(); e++) {
                if (*e == *i) {
                    Check2++;
                }
            }
            if (Check2 == 0) {
                ConsonantsFound.insert(*i);
            }
        }

        word.clear();
        Check++;
    }

    if (VowelsFound.empty()) {
        cout << "\nThere is no vowel letter that is in all words!" << endl;
    }
    else {
        cout << "\nVowel letter that is in all words:" << endl;
        for (auto i = VowelsFound.begin(); i != VowelsFound.end(); i++) {
            cout << *i << endl;
        }
    }

    if (ConsonantsFound.empty()) {
        cout << "\nThere is no consonant letter that is in all words!" << endl;
    }
    else {
        cout << "\nConsonant letter that is in all words:" << endl;
        for (auto Consonant : ConsonantsFound) {
            cout << Consonant << endl;
        }
    }
}
