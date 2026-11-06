#include<iostream>
using namespace std;
struct Stack {
    int arr[100];
    int topIndex;
    Stack(){ topIndex = -1; }
    void push(int v){ arr[++topIndex] = v; }
    int pop(){ return arr[topIndex--]; }
    bool empty(){ return topIndex == -1; }
};
struct Queue {
    Stack s1, s2;
    void enqueue(int v){ s1.push(v); }
    int dequeue(){
        if(s2.empty()){
            while(!s1.empty()) s2.push(s1.pop());
        }
        return s2.pop();
    }
    int front(){
        if(s2.empty()){
            while(!s1.empty()) s2.push(s1.pop());
        }
        int val = s2.pop();
        s2.push(val);
        return val;
    }
    void display(){
        Stack temp;
        if(s2.empty()){
            while(!s1.empty()) s2.push(s1.pop());
        }
        while(!s2.empty()){
            int val = s2.pop();
            cout<<val<<" ";
            temp.push(val);
        }
        while(!temp.empty()){
            s2.push(temp.pop());
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    int ch, v;
    while(true){
        cout<<"1 Enqueue 2 Dequeue 3 Front 4 Display 5 Exit\n";
        cin>>ch;
        if(ch==1){ cin>>v; q.enqueue(v); }
        else if(ch==2){ cout<<q.dequeue()<<endl; }
        else if(ch==3){ cout<<q.front()<<endl; }
        else if(ch==4){ q.display(); }
        else if(ch==5){ break; }
    }
    return 0;
}
