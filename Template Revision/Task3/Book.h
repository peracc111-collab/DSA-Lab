#pragma once
#include <iostream>
#include <string>
#include "LibraryItem.h"
using namespace std;

class Book : public LibraryItem {
    string title, author;
    int pages;
public:
    Book(const string& t = "", const string& a = "", int p = 0)
        : title(t), author(a), pages(p) {}

    string getTitle() const { return title; }
    int getPages() const { return pages; }

    void display() const override {
        cout << "Book: \"" << title << "\" by " << author
                  << ", " << pages << " pages\n";
    }

    bool operator==(const Book& o) const { return title == o.title; }  // search by title
    bool operator<(const Book& o) const { return pages < o.pages; }    // sort by pages
};
