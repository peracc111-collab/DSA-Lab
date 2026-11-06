#include<iostream>
#include<string>
using namespace std;
struct PrintJob {
    int jobID;
    string userName;
    int pages;
};
struct CQueue {
    PrintJob arr[10];
    int f, r, count;
    CQueue(){ f=-1; r=-1; count=0; }
    bool isFull(){ return count==10; }
    bool isEmpty(){ return count==0; }
    void enqueue(PrintJob p){
        if(isFull()) return;
        if(f==-1) f=0;
        r = (r+1)%10;
        arr[r] = p;
        count++;
    }
    PrintJob dequeue(){
        PrintJob p;
        if(isEmpty()) return p;
        p = arr[f];
        f = (f+1)%10;
        count--;
        if(count==0){ f=-1; r=-1; }
        return p;
    }
    PrintJob peek(){
        if(isEmpty()) return PrintJob();
        return arr[f];
    }
    void display(){
        for(int i=0; i<count; i++){
            PrintJob p = arr[(f+i)%10];
            cout<<p.jobID<<" "<<p.userName<<" "<<p.pages<<endl;
        }
    }
};
int main(){
    CQueue q;
    int ch;
    PrintJob p;
    while(true){
        cout<<"1 Submit 2 Process Next 3 Display Next 4 Display All 5 Total 6 Exit\n";
        cin>>ch;
        if(ch==1){ cin>>p.jobID>>p.userName>>p.pages; q.enqueue(p); }
        else if(ch==2){ q.dequeue(); }
        else if(ch==3){ p=q.peek(); cout<<p.userName<<endl; }
        else if(ch==4){ q.display(); }
        else if(ch==5){ cout<<q.count<<endl; }
        else if(ch==6){ break; }
    }
    return 0;
}
