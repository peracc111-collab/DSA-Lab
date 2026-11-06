#include<iostream>
#include<string>
using namespace std;
template <typename T>
void selectionSort(T A[], int N){
    for(int i=0; i<N-1; i++){
        int smallSub = i;
        for(int j=i+1; j<N; j++){
            if(A[j] < A[smallSub]){
                smallSub = j;
            }
        }
        T temp = A[i];
        A[i] = A[smallSub];
        A[smallSub] = temp;
    }
}
template <typename T>
void printArray(T A[], int N){
    for(int i=0; i<N; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int intArray[5] = {64, 25, 12, 22, 11};
    cout<<"Original integer array: ";
    printArray(intArray, 5);
    selectionSort(intArray, 5);
    cout<<"Sorted integer array: ";
    printArray(intArray, 5);
    string stringArray[4] = {"apple", "orange", "banana", "grape"};
    cout<<"\nOriginal string array: ";
    printArray(stringArray, 4);
    selectionSort(stringArray, 4);
    cout<<"Sorted string array: ";
    printArray(stringArray, 4);
    return 0;
}
