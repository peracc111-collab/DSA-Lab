#pragma once
#include <utility>
using namespace std;

// Template versions of the Lab 1 algorithms, written to work on any array/vector data.
// Elements must support == and < where used.

template <typename T>
int linearSearch(const T* arr, int n, const T& key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

// array must already be sorted in the same order that operator< defines
template <typename T>
int binarySearch(const T* arr, int n, const T& key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

template <typename T>
void selectionSort(T* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        if (minIdx != i) swap(arr[i], arr[minIdx]);
    }
}
