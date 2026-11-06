#include<iostream>
using namespace std;
struct TicketQueue {
    int arr[100];
    int f, r, count;
    TicketQueue(){ f=0; r=-1; count=0; }
    void enqueue(int id){
        if(count==100) return;
        r=(r+1)%100; arr[r]=id; count++;
    }
    void dequeue(){
        if(count==0) return;
        f=(f+1)%100; count--;
    }
    int front(){ return count==0 ? -1 : arr[f]; }
    void display(){
        for(int i=0; i<count; i++) cout<<arr[(f+i)%100]<<" ";
        cout<<endl;
    }
};
int main(){
    TicketQueue tq;
    int ch, id;
    while(true){
        cout<<"1 Add Ticket 2 Resolve 3 Next Ticket 4 Display All 5 Exit\n";
        cin>>ch;
        if(ch==1){ cin>>id; tq.enqueue(id); }
        else if(ch==2){ tq.dequeue(); }
        else if(ch==3){ cout<<tq.front()<<endl; }
        else if(ch==4){ tq.display(); }
        else if(ch==5){ break; }
    }
    return 0;
}
