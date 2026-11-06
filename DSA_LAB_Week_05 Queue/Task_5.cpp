#include<iostream>
#include<string>
using namespace std;
struct PrintQueue {
    string arr[100];
    int f, r, count;
    PrintQueue(){ f=0; r=-1; count=0; }
    void enqueue(string doc){
        if(count==100) return;
        r=(r+1)%100; arr[r]=doc; count++;
    }
    void dequeue(){
        if(count==0) return;
        f=(f+1)%100; count--;
    }
    string front(){ return count==0 ? "" : arr[f]; }
    void display(){
        for(int i=0; i<count; i++) cout<<arr[(f+i)%100]<<" ";
        cout<<endl;
    }
};
int main(){
    PrintQueue pq;
    int ch;
    string doc;
    while(true){
        cout<<"1 Add Job 2 Print 3 Front Job 4 Display All 5 Exit\n";
        cin>>ch;
        if(ch==1){ cin>>doc; pq.enqueue(doc); }
        else if(ch==2){ pq.dequeue(); }
        else if(ch==3){ cout<<pq.front()<<endl; }
        else if(ch==4){ pq.display(); }
        else if(ch==5){ break; }
    }
    return 0;
}
