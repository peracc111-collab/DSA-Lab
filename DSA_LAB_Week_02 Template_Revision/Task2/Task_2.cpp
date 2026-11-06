#include <iostream>
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
using namespace std;

int main() {
    FullTimeEmployee full;
    PartTimeEmployee part;

    full.setSalary(80000);
    part.setDetails(60, 500);   // 60 hours at 500 per hour

    Employee* employees[2] = { &full, &part };
    string names[2] = { "Full-time employee", "Part-time employee" };

    for (int i = 0; i < 2; i++)
        cout << names[i] << " salary: " << employees[i]->calculateSalary() << endl;
    return 0;
}
