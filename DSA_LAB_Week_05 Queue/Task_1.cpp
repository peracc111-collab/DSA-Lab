#include<iostream>
using namespace std;
template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};
template <typename T>
class myQueue : public AbstractQueue<T> {
    T *arr;
    int capacity, f, r, count;
public:
    myQueue(int size=100){ capacity=size; arr=new T[capacity]; f=0; r=-1; count=0; }
    ~myQueue(){ delete[] arr; }
    void enQueue(T value){
        if(isFull()) return;
        r = (r+1)%capacity;
        arr[r] = value;
        count++;
    }
    T deQueue(){
        if(isEmpty()) return T();
        T val = arr[f];
        f = (f+1)%capacity;
        count--;
        return val;
    }
    T front() const{ return isEmpty() ? T() : arr[f]; }
    bool isEmpty() const{ return count == 0; }
    bool isFull() const{ return count == capacity; }
    void display() const{
        for(int i=0; i<count; i++){
            cout<<arr[(f+i)%capacity]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    myQueue<int> q(5);
    int ch, v;
    while(true){
        cout<<"1 Enqueue 2 Dequeue 3 Front 4 Display 5 Exit\n";
        cin>>ch;
        if(ch==1){ cin>>v; q.enQueue(v); }
        else if(ch==2){ cout<<q.deQueue()<<endl; }
        else if(ch==3){ cout<<q.front()<<endl; }
        else if(ch==4){ q.display(); }
        else if(ch==5){ break; }
    }
    return 0;
}
