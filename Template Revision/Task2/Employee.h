#pragma once

class Employee 
{
public:
    virtual double calculateSalary() const = 0;
    virtual ~Employee() {}
};
