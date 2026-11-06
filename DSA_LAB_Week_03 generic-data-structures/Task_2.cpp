#include<iostream>
using namespace std;
template <class Type>
class List {
protected:
    Type *arr;
    int maxSize;
    int currentSize;
public:
    List(int mSize = 100){ maxSize = mSize; currentSize = 0; arr = new Type[maxSize]; }
    List(const List &other){
        maxSize = other.maxSize; currentSize = other.currentSize; arr = new Type[maxSize];
        for(int i=0; i<currentSize; i++) arr[i] = other.arr[i];
    }
    virtual ~List(){ delete[] arr; }
    virtual void addElementAtFirstIndex(Type val) = 0;
    virtual void addElementAtLastIndex(Type val) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
};
template <class Type>
class MyList : public List<Type> {
public:
    MyList(int mSize = 100) : List<Type>(mSize) {}
    MyList(const MyList &other) : List<Type>(other) {}
    ~MyList(){}
    void addElementAtFirstIndex(Type val){
        if(full()) return;
        for(int i=this->currentSize; i>0; i--) this->arr[i] = this->arr[i-1];
        this->arr[0] = val;
        this->currentSize++;
    }
    void addElementAtLastIndex(Type val){
        if(full()) return;
        this->arr[this->currentSize++] = val;
    }
    Type removeElementFromEnd(){
        if(empty()) return Type();
        return this->arr[--this->currentSize];
    }
    void removeElementFromStart(){
        if(empty()) return;
        for(int i=0; i<this->currentSize-1; i++) this->arr[i] = this->arr[i+1];
        this->currentSize--;
    }
    bool empty(){ return this->currentSize == 0; }
    bool full(){ return this->currentSize == this->maxSize; }
    int size(){ return this->currentSize; }
    bool insertAt(int index, Type value){
        if(full() || index<0 || index>this->currentSize) return false;
        for(int i=this->currentSize; i>index; i--) this->arr[i] = this->arr[i-1];
        this->arr[index] = value;
        this->currentSize++;
        return true;
    }
    Type last(){
        if(empty()) return Type();
        return this->arr[this->currentSize-1];
    }
    bool search(Type value){
        for(int i=0; i<this->currentSize; i++){
            if(this->arr[i] == value) return true;
        }
        return false;
    }
};
int main(){
    MyList<int> list;
    int choice, val, idx;
    while(true){
        cout<<"1 Add First 2 Add Last 3 Remove End 4 Remove Start 5 Size 6 Insert 7 Search 8 Exit\n";
        cin>>choice;
        if(choice==1){ cin>>val; list.addElementAtFirstIndex(val); }
        else if(choice==2){ cin>>val; list.addElementAtLastIndex(val); }
        else if(choice==3){ cout<<list.removeElementFromEnd()<<endl; }
        else if(choice==4){ list.removeElementFromStart(); }
        else if(choice==5){ cout<<list.size()<<endl; }
        else if(choice==6){ cin>>idx>>val; list.insertAt(idx, val); }
        else if(choice==7){ cin>>val; cout<<list.search(val)<<endl; }
        else if(choice==8){ break; }
    }
    return 0;
}
