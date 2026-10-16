#pragma once
#include <iostream>
using namespace std;

// Task 1: generic abstract class
template <typename Type>
class List {
protected:
    Type *arr;
    int maxSize;
    int currentSize;

public:
    // parameterized constructor with default argument
    List(int size = 10) {
        maxSize = (size > 0) ? size : 10;
        currentSize = 0;
        arr = new Type[maxSize];
    }

    // copy constructor (deep copy)
    List(const List& other) {
        maxSize = other.maxSize;
        currentSize = other.currentSize;
        arr = new Type[maxSize];
        for (int i = 0; i < currentSize; i++)
            arr[i] = other.arr[i];
    }

    // assignment operator (keeps copies safe when using =)
    List& operator=(const List& other) {
        if (this != &other) {
            delete[] arr;
            maxSize = other.maxSize;
            currentSize = other.currentSize;
            arr = new Type[maxSize];
            for (int i = 0; i < currentSize; i++)
                arr[i] = other.arr[i];
        }
        return *this;
    }

    // virtual destructor
    virtual ~List() { delete[] arr; }

    // pure virtual functions
    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
};
