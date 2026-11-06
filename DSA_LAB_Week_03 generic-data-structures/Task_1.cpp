#include<iostream>
using namespace std;
template <class Type>
class List {
protected:
    Type *arr;
    int maxSize;
    int currentSize;
public:
    List(int mSize = 100){
        maxSize = mSize;
        currentSize = 0;
        arr = new Type[maxSize];
    }
    List(const List &other){
        maxSize = other.maxSize;
        currentSize = other.currentSize;
        arr = new Type[maxSize];
        for(int i=0; i<currentSize; i++) arr[i] = other.arr[i];
    }
    virtual ~List(){
        delete[] arr;
    }
    virtual void addElementAtFirstIndex(Type val) = 0;
    virtual void addElementAtLastIndex(Type val) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
};
int main(){
    return 0;
}
