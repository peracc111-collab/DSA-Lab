#include<iostream>
using namespace std;
class Employee {
public:
    virtual void calculateSalary() = 0;
};
class FullTimeEmployee : public Employee {
    float fixedSalary;
public:
    FullTimeEmployee(float s){ fixedSalary = s; }
    void calculateSalary(){
        cout<<"Full-Time Salary: $"<<fixedSalary<<endl;
    }
};
class PartTimeEmployee : public Employee {
    float hours, rate;
public:
    PartTimeEmployee(float h, float r){ hours = h; rate = r; }
    void calculateSalary(){
        cout<<"Part-Time Salary: $"<<hours * rate<<endl;
    }
};
int main(){
    FullTimeEmployee fte(5000);
    PartTimeEmployee pte(40, 15);
    fte.calculateSalary();
    pte.calculateSalary();
    return 0;
}
