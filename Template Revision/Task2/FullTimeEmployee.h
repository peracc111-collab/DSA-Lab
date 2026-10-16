#pragma once
#include "Employee.h"

class FullTimeEmployee : public Employee 
{
    double fixedSalary;


public:
    FullTimeEmployee() : fixedSalary(0) {}
    void setSalary(double s) { fixedSalary = s; }
    double calculateSalary() const override { return fixedSalary; }
};
