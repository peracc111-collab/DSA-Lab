#pragma once
#include "Employee.h"

class PartTimeEmployee : public Employee 
{
    double hoursWorked;
    double hourlyRate;


public:
    PartTimeEmployee() : hoursWorked(0), hourlyRate(0) {}
    void setDetails(double hours, double rate) { hoursWorked = hours; hourlyRate = rate; }
    double calculateSalary() const override { return hoursWorked * hourlyRate; }
};
