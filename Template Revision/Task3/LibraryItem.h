#pragma once

// Abstract base class for everything the library holds
class LibraryItem {
public:
    virtual void display() const = 0;   // pure virtual
    virtual ~LibraryItem() {}
};
