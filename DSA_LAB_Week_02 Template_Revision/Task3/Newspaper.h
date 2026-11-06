#pragma once
#include <iostream>
#include <string>
#include "LibraryItem.h"
using namespace std;

class Newspaper : public LibraryItem 
{
    string name, date, edition;
public:
    Newspaper(const string& n = "", const string& d = "", const string& e = "")
        : name(n), date(d), edition(e) {}

    string getName() const { return name; }
    string getEdition() const { return edition; }

    void display() const override 
    {
        cout << "Newspaper: " << name << ", " << date << ", " << edition << "\n";
    }

    bool operator==(const Newspaper& o) const { return name == o.name; }        // search by name
    bool operator<(const Newspaper& o) const { return edition < o.edition; }    // sort by edition
};
