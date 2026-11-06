#include<iostream>
#include<string>
using namespace std;
struct Booking {
    int customerID;
    string customerName;
    int numberOfTickets;
};
struct CQueue {
    Booking arr[10];
    int f, r, count;
    CQueue(){ f=-1; r=-1; count=0; }
    bool isFull(){ return count==10; }
    bool isEmpty(){ return count==0; }
    void enqueue(Booking b){
        if(isFull()) return;
        if(f==-1) f=0;
        r = (r+1)%10;
        arr[r] = b;
        count++;
    }
    Booking dequeue(){
        Booking b;
        if(isEmpty()) return b;
        b = arr[f];
        f = (f+1)%10;
        count--;
        if(count==0){ f=-1; r=-1; }
        return b;
    }
    Booking peek(){
        if(isEmpty()) return Booking();
        return arr[f];
    }
    void display(){
        for(int i=0; i<count; i++){
            Booking b = arr[(f+i)%10];
            cout<<b.customerID<<" "<<b.customerName<<" "<<b.numberOfTickets<<endl;
        }
    }
};
int main(){
    CQueue q;
    int ch;
    Booking b;
    while(true){
        cout<<"1 Book 2 Cancel First 3 Next Booking 4 Display All 5 Total 6 Exit\n";
        cin>>ch;
        if(ch==1){ cin>>b.customerID>>b.customerName>>b.numberOfTickets; q.enqueue(b); }
        else if(ch==2){ q.dequeue(); }
        else if(ch==3){ b=q.peek(); cout<<b.customerName<<endl; }
        else if(ch==4){ q.display(); }
        else if(ch==5){ cout<<q.count<<endl; }
        else if(ch==6){ break; }
    }
    return 0;
}
