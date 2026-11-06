#include<iostream>
using namespace std;
struct CharStack {
    char arr[500];
    int top;
    CharStack(){ top = -1; }
    void push(char c){ arr[++top] = c; }
    char pop(){ return top>=0 ? arr[top--] : '\0'; }
    bool empty(){ return top == -1; }
};
int main(){
    CharStack undoStack;
    CharStack redoStack;
    int ch;
    char c;
    while(true){
        cout<<"1 Type char 2 Delete char 3 Undo 4 Redo 5 Print text 6 Exit\n";
        cin>>ch;
        if(ch==1){
            cin>>c;
            undoStack.push(c);
            while(!redoStack.empty()) redoStack.pop();
        }else if(ch==2){
            if(!undoStack.empty()) redoStack.push(undoStack.pop());
        }else if(ch==3){
            if(!undoStack.empty()) redoStack.push(undoStack.pop());
        }else if(ch==4){
            if(!redoStack.empty()) undoStack.push(redoStack.pop());
        }else if(ch==5){
            CharStack temp;
            while(!undoStack.empty()) temp.push(undoStack.pop());
            while(!temp.empty()){
                char x = temp.pop();
                cout<<x;
                undoStack.push(x);
            }
            cout<<endl;
        }else if(ch==6){
            break;
        }
    }
    return 0;
}
