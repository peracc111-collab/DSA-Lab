#include<iostream>
using namespace std;
struct Queue {
    int arr[100];
    int f, r, count;
    Queue(){ f=0; r=-1; count=0; }
    void enqueue(int v){ r=(r+1)%100; arr[r]=v; count++; }
    int dequeue(){ int v=arr[f]; f=(f+1)%100; count--; return v; }
    int front(){ return arr[f]; }
    bool isEmpty(){ return count==0; }
};
struct Stack {
    int arr[100];
    int topIndex;
    Stack(){ topIndex = -1; }
    void push(int v){ arr[++topIndex] = v; }
    int pop(){ return arr[topIndex--]; }
};
int main(){
    Queue q;
    int n, val, k;
    cout<<"Enter N: "; cin>>n;
    for(int i=0; i<n; i++){
        cin>>val; q.enqueue(val);
    }
    cout<<"Enter K: "; cin>>k;
    if(k>1 && k<=n){
        Stack s;
        for(int i=0; i<k; i++) s.push(q.dequeue());
        while(s.topIndex != -1) q.enqueue(s.pop());
        for(int i=0; i<n-k; i++) q.enqueue(q.dequeue());
    }
    while(!q.isEmpty()) cout<<q.dequeue()<<" ";
    cout<<endl;
    return 0;
}
