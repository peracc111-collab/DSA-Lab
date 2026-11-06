#include<iostream>
using namespace std;
class Shape {
public:
    virtual void area() = 0;
};
class Circle : public Shape {
    float radius;
public:
    Circle(float r){ radius = r; }
    void area(){
        cout<<"Circle Area: "<<3.14 * radius * radius<<endl;
    }
};
class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w){ length = l; width = w; }
    void area(){
        cout<<"Rectangle Area: "<<length * width<<endl;
    }
};
int main(){
    Circle c(5.0);
    Rectangle r(4.0, 6.0);
    c.area();
    r.area();
    return 0;
}
