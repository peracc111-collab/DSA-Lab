#pragma once
#include "List.h"

// Task 2
template <typename T>
class MyList : public List<T> 
{

public:
    MyList(int size = 10) : List<T>(size) {}
    MyList(const MyList& other) : List<T>(other) {}
    virtual ~MyList() {}

    bool empty() const { return this->currentSize == 0; }
    bool full() const { return this->currentSize == this->maxSize; }
    int size() const { return this->currentSize; }

    void addElementAtFirstIndex(T value) override {
        if (full()) { cout << "List is full.\n"; return; }
        for (int i = this->currentSize; i > 0; i--)
            this->arr[i] = this->arr[i - 1];
        this->arr[0] = value;
        this->currentSize++;
    }

    void addElementAtLastIndex(T value) override {
        if (full()) { cout << "List is full.\n"; return; }
        this->arr[this->currentSize++] = value;
    }

    T removeElementFromEnd() override {
        if (empty()) { cout << "List is empty.\n"; return T(); }
        return this->arr[--this->currentSize];
    }

    void removeElementFromStart() override {
        if (empty()) { cout << "List is empty.\n"; return; }
        for (int i = 0; i < this->currentSize - 1; i++)
            this->arr[i] = this->arr[i + 1];
        this->currentSize--;
    }

    // valid indexes: 0 .. currentSize (currentSize means append)
    bool insertAt(int index, T value) {
        if (full() || index < 0 || index > this->currentSize)
            return false;
        for (int i = this->currentSize; i > index; i--)
            this->arr[i] = this->arr[i - 1];
        this->arr[index] = value;
        this->currentSize++;
        return true;
    }

    T last() const {
        if (empty()) { cout << "List is empty.\n"; return T(); }
        return this->arr[this->currentSize - 1];
    }

    bool search(T value) const {
        for (int i = 0; i < this->currentSize; i++)
            if (this->arr[i] == value) return true;
        return false;
    }

    void display() const 
    {
        if (empty()) 
        { cout << "List is empty.\n"; return; }
        for (int i = 0; i < this->currentSize; i++) 
        {
            cout << this->arr[i] << " ";
        }
            
        cout << endl;
    }
};
