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
        for(int i=0; i<this->currentSize; i++) if(this->arr[i] == value) return true;
        return false;
    }
};
template <class Type>
class CustomList : public MyList<Type> {
    bool isPrime(int n){
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++) if(n%i==0) return false;
        return true;
    }
public:
    CustomList(int mSize = 100) : MyList<Type>(mSize) {}
    CustomList(const CustomList &other) : MyList<Type>(other) {}
    ~CustomList(){}
    Type sum_ofPrime(){
        Type sum = 0;
        for(int i=0; i<this->currentSize; i++){
            if(isPrime(this->arr[i])) sum += this->arr[i];
        }
        return sum;
    }
    Type secondMaxEven(){
        Type max1 = -1, max2 = -1;
        for(int i=0; i<this->currentSize; i++){
            if(this->arr[i]%2==0){
                if(this->arr[i] > max1){ max2 = max1; max1 = this->arr[i]; }
                else if(this->arr[i] > max2 && this->arr[i] != max1){ max2 = this->arr[i]; }
            }
        }
        return max2;
    }
    Type secondMinOdd(){
        Type min1 = 99999, min2 = 99999;
        for(int i=0; i<this->currentSize; i++){
            if(this->arr[i]%2!=0){
                if(this->arr[i] < min1){ min2 = min1; min1 = this->arr[i]; }
                else if(this->arr[i] < min2 && this->arr[i] != min1){ min2 = this->arr[i]; }
            }
        }
        return min2;
    }
    void printDuplicates(){
        for(int i=0; i<this->currentSize; i++){
            bool isDup = false;
            for(int j=i+1; j<this->currentSize; j++){
                if(this->arr[i] == this->arr[j]){ isDup = true; break; }
            }
            if(isDup) cout<<this->arr[i]<<" ";
        }
        cout<<endl;
    }
    void rotateClockwaise(int r){
        if(this->currentSize<=1) return;
        int mid = this->currentSize/2;
        for(int k=0; k<r; k++){
            Type temp1 = this->arr[mid-1];
            for(int i=mid-1; i>0; i--) this->arr[i] = this->arr[i-1];
            this->arr[0] = temp1;
            Type temp2 = this->arr[this->currentSize-1];
            for(int i=this->currentSize-1; i>mid; i--) this->arr[i] = this->arr[i-1];
            this->arr[mid] = temp2;
        }
    }
    void rotateanitclockwaise(int rt){
        if(this->currentSize<=1) return;
        int mid = this->currentSize/2;
        for(int k=0; k<rt; k++){
            Type temp1 = this->arr[0];
            for(int i=0; i<mid-1; i++) this->arr[i] = this->arr[i+1];
            this->arr[mid-1] = temp1;
            Type temp2 = this->arr[mid];
            for(int i=mid; i<this->currentSize-1; i++) this->arr[i] = this->arr[i+1];
            this->arr[this->currentSize-1] = temp2;
        }
    }
};
int main(){
    CustomList<int> cl;
    int c, val;
    while(true){
        cout<<"1 Add Last 2 Sum Prime 3 Second Max Even 4 Second Min Odd 5 Duplicates 6 RotCW 7 RotACW 8 Exit\n";
        cin>>c;
        if(c==1){ cin>>val; cl.addElementAtLastIndex(val); }
        else if(c==2){ cout<<cl.sum_ofPrime()<<endl; }
        else if(c==3){ cout<<cl.secondMaxEven()<<endl; }
        else if(c==4){ cout<<cl.secondMinOdd()<<endl; }
        else if(c==5){ cl.printDuplicates(); }
        else if(c==6){ cin>>val; cl.rotateClockwaise(val); }
        else if(c==7){ cin>>val; cl.rotateanitclockwaise(val); }
        else if(c==8){ break; }
    }
    return 0;
}
