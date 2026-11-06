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
    void push(T value){ if(!isFull()) arr[++topIndex] = value; }
    T pop(){ return isEmpty() ? T() : arr[topIndex--]; }
    T top() const{ return isEmpty() ? T() : arr[topIndex]; }
    bool isEmpty() const{ return topIndex == -1; }
    bool isFull() const{ return topIndex == capacity - 1; }
    void display() const{
        for(int i=topIndex; i>=0; i--) cout<<arr[i]<<" ";
        cout<<endl;
    }
};
template <typename T>
class EnhancedStack {
    myStack<T> mainStack;
    myStack<T> minStack;
public:
    void push(T val){
        mainStack.push(val);
        if(minStack.isEmpty() || val <= minStack.top()) minStack.push(val);
    }
    T pop(){
        T val = mainStack.pop();
        if(val == minStack.top()) minStack.pop();
        return val;
    }
    T top(){ return mainStack.top(); }
    bool isEmpty(){ return mainStack.isEmpty(); }
    bool isFull(){ return mainStack.isFull(); }
    void display(){ mainStack.display(); }
    T getMin(){ return minStack.top(); }
};
int main(){
    EnhancedStack<int> es;
    int ch, v;
    while(true){
        cout<<"1 Push 2 Pop 3 Top 4 Empty? 5 Full? 6 Display 7 Show Min 8 Exit\n";
        cin>>ch;
        if(ch==1){ cin>>v; es.push(v); }
        else if(ch==2){ cout<<es.pop()<<endl; }
        else if(ch==3){ cout<<es.top()<<endl; }
        else if(ch==4){ cout<<es.isEmpty()<<endl; }
        else if(ch==5){ cout<<es.isFull()<<endl; }
        else if(ch==6){ es.display(); }
        else if(ch==7){ cout<<es.getMin()<<endl; }
        else if(ch==8){ break; }
    }
    return 0;
}
