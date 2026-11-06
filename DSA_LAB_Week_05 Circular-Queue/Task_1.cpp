#include<iostream>
#include<string>
using namespace std;
struct Customer {
    string name;
    string transaction;
};
struct CQueue {
    Customer arr[10];
    int f, r, count;
    CQueue(){ f=-1; r=-1; count=0; }
    bool isFull(){ return count==10; }
    bool isEmpty(){ return count==0; }
    void enqueue(Customer c){
        if(isFull()){ cout<<"Overflow\n"; return; }
        if(f==-1) f=0;
        r = (r+1)%10;
        arr[r] = c;
        count++;
    }
    Customer dequeue(){
        Customer c;
        if(isEmpty()){ cout<<"Underflow\n"; return c; }
        c = arr[f];
        f = (f+1)%10;
        count--;
        if(count==0){ f=-1; r=-1; }
        return c;
    }
    void display(){
        for(int i=0; i<count; i++){
            Customer c = arr[(f+i)%10];
            cout<<c.name<<" - "<<c.transaction<<endl;
        }
    }
    int total(){ return count; }
};
int main(){
    CQueue q;
    int ch;
    Customer c;
    while(true){
        cout<<"1 Add 2 Serve 3 Display 4 Total 5 Exit\n";
        cin>>ch;
        if(ch==1){ cin>>c.name>>c.transaction; q.enqueue(c); }
        else if(ch==2){ c = q.dequeue(); if(c.name != "") cout<<"Served: "<<c.name<<endl; }
        else if(ch==3){ q.display(); }
        else if(ch==4){ cout<<q.total()<<endl; }
        else if(ch==5){ break; }
    }
    return 0;
}
