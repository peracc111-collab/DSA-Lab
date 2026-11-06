#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "Newspaper.h"
#include "SearchSort.h"
using namespace std;

class Library {
    static const int MAX = 100;
    Book books[MAX];
    Newspaper newspapers[MAX];
    int bookCount;
    int newspaperCount;
public:
    Library() : bookCount(0), newspaperCount(0) {}

    void addBook(const Book& b) 
    {
        if (bookCount < MAX) books[bookCount++] = b;
        else cout << "Book shelf is full.\n";
    }

    void addNewspaper(const Newspaper& n) 
    {
        if (newspaperCount < MAX) newspapers[newspaperCount++] = n;
        else cout << "Newspaper rack is full.\n";
    }

    void displayCollection() const {
        for (int i = 0; i < bookCount; i++) books[i].display();
        for (int i = 0; i < newspaperCount; i++) newspapers[i].display();
    }

    void sortBooksByPages() { selectionSort(books, bookCount); }
    void sortNewspapersByEdition() { selectionSort(newspapers, newspaperCount); }

    // collections are sorted by pages/edition, not title/name, so linear search is used
    Book* searchBookByTitle(const string& title) 
    {
        Book key(title);
        int i = linearSearch(books, bookCount, key);
        return i == -1 ? nullptr : &books[i];
    }

    Newspaper* searchNewspaperByName(const string& name) 
    {
        Newspaper key(name);
        int i = linearSearch(newspapers, newspaperCount, key);
        return i == -1 ? nullptr : &newspapers[i];
    }
};
