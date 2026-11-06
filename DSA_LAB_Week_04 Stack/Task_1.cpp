#include<iostream>
using namespace std;
template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};
template <typename T>
class myStack : public AbstractStack<T> {
    T *arr;
    int capacity, topIndex;
public:
    myStack(int size=100){ capacity = size; arr = new T[capacity]; topIndex = -1; }
    ~myStack(){ delete[] arr; }
    void push(T value){
        if(!isFull()){ topIndex++; arr[topIndex] = value; }
    }
    T pop(){
        if(isEmpty()) return T();
        T val = arr[topIndex];
        topIndex--;
        return val;
    }
    T top() const{
        if(isEmpty()) return T();
        return arr[topIndex];
    }
    bool isEmpty() const{ return topIndex == -1; }
    bool isFull() const{ return topIndex == capacity - 1; }
    void display() const{
        for(int i=topIndex; i>=0; i--) cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main(){
    myStack<int> s;
    int ch, v;
    while(true){
        cout<<"1 Push 2 Pop 3 Top 4 Empty? 5 Full? 6 Display 7 Exit\n";
        cin>>ch;
        if(ch==1){ cin>>v; s.push(v); }
        else if(ch==2){ cout<<s.pop()<<endl; }
        else if(ch==3){ cout<<s.top()<<endl; }
        else if(ch==4){ cout<<s.isEmpty()<<endl; }
        else if(ch==5){ cout<<s.isFull()<<endl; }
        else if(ch==6){ s.display(); }
        else if(ch==7){ break; }
    }
    return 0;
}
