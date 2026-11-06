#include<iostream>
#include<string>
using namespace std;
struct myCarStack {
    string cars[8];
    int top;
    myCarStack(){ top = -1; }
    void push(string c){ if(top<7) cars[++top] = c; }
    string pop(){ return top>=0 ? cars[top--] : ""; }
    string peek(){ return top>=0 ? cars[top] : ""; }
    bool empty(){ return top == -1; }
    bool full(){ return top == 7; }
    int size(){ return top + 1; }
};
int main(){
    myCarStack lot;
    int ch;
    string plate;
    while(true){
        cout<<"1 Park Car 2 Remove Car 3 Search Car 4 View Current 5 Total Cars 6 Exit\n";
        cin>>ch;
        if(ch==1){
            cin>>plate;
            if(!lot.full()) lot.push(plate);
            else cout<<"Full\n";
        }else if(ch==2){
            cin>>plate;
            myCarStack temp;
            bool found = false;
            while(!lot.empty()){
                string c = lot.pop();
                if(c == plate){ found = true; break; }
                temp.push(c);
            }
            while(!temp.empty()) lot.push(temp.pop());
            if(found) cout<<"Removed\n"; else cout<<"Not found\n";
        }else if(ch==3){
            cin>>plate;
            myCarStack temp;
            bool found = false;
            while(!lot.empty()){
                string c = lot.pop();
                temp.push(c);
                if(c == plate) found = true;
            }
            while(!temp.empty()) lot.push(temp.pop());
            if(found) cout<<"Found\n"; else cout<<"Not found\n";
        }else if(ch==4){
            cout<<"Top car: "<<lot.peek()<<endl;
        }else if(ch==5){
            cout<<"Total: "<<lot.size()<<endl;
        }else if(ch==6){
            break;
        }
    }
    return 0;
}
