#include<iostream>
#include<string>
using namespace std;
template <typename T>
int binarySearch(T A[], int N, T value){
    int low = 0, high = N-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(A[mid] == value) return mid;
        else if(A[mid] < value) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
template <typename T>
void printSearchResult(int index, T key){
    if(index != -1) cout<<key<<" found at index "<<index<<endl;
    else cout<<key<<" not found"<<endl;
}
int main(){
    int intArray[5] = {11, 12, 22, 25, 64};
    int intKey = 22;
    int intIndex = binarySearch(intArray, 5, intKey);
    printSearchResult(intIndex, intKey);
    float floatArray[4] = {0.57, 1.62, 2.71, 3.14};
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray, 4, floatKey);
    printSearchResult(floatIndex, floatKey);
    string stringArray[4] = {"apple", "banana", "grape", "orange"};
    string stringKey = "grape";
    int stringIndex = binarySearch(stringArray, 4, stringKey);
    printSearchResult(stringIndex, stringKey);
    return 0;
}
