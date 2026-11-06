#include<iostream>
#include<string>
using namespace std;
struct Package {
    int id;
    string address;
    int start_time;
    int end_time;
};
struct DeliveryQueue {
    Package arr[100];
    int f, r, count;
    DeliveryQueue(){ f=0; r=-1; count=0; }
    void enqueue(Package p){
        r=(r+1)%100; arr[r]=p; count++;
    }
    void dequeue(){
        if(count>0){ f=(f+1)%100; count--; }
    }
    Package front(){ return arr[f]; }
    void display(){
        for(int i=0; i<count; i++){
            Package p = arr[(f+i)%100];
            cout<<"ID:"<<p.id<<" Addr:"<<p.address<<" Window:"<<p.start_time<<"-"<<p.end_time<<endl;
        }
    }
    void timeToDeliver(int currentTime){
        if(count==0) return;
        Package p = arr[f];
        if(currentTime > p.end_time){
            cout<<"Expired, skipping ID "<<p.id<<endl;
            dequeue();
        }else if(currentTime >= p.start_time){
            cout<<"Delivered ID "<<p.id<<endl;
            dequeue();
        }else{
            cout<<"Too early for ID "<<p.id<<endl;
        }
    }
};
int main(){
    DeliveryQueue dq;
    int ch, time;
    Package p;
    while(true){
        cout<<"1 Add Package 2 Check Delivery 3 Display 4 Exit\n";
        cin>>ch;
        if(ch==1){
            cin>>p.id>>p.address>>p.start_time>>p.end_time;
            dq.enqueue(p);
        }else if(ch==2){
            cout<<"Current Time: "; cin>>time;
            dq.timeToDeliver(time);
        }else if(ch==3){
            dq.display();
        }else if(ch==4){
            break;
        }
    }
    return 0;
}
