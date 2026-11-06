#pragma once
#include "MyList.h"

// Task 3
template <typename T>
class CustomList : public MyList<T> 
{
    // helpers: treat a value as a whole number
    static bool isWhole(T x) { return x == (T)(long long)x; }

    static bool isPrime(T x) {
        if (!isWhole(x)) return false;
        long long n = (long long)x;
        if (n < 2) return false;
        for (long long i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    // rotate arr[lo, hi) to the right by r positions
    void rotateRight(int lo, int hi, int r) {
        int len = hi - lo;
        if (len <= 1) return;
        r %= len;
        if (r == 0) return;
        T *tmp = new T[len];
        for (int i = 0; i < len; i++)
            tmp[(i + r) % len] = this->arr[lo + i];
        for (int i = 0; i < len; i++)
            this->arr[lo + i] = tmp[i];
        delete[] tmp;
    }

public:

    CustomList(int size = 10) : MyList<T>(size) {}

    CustomList(const CustomList& other) : MyList<T>(other) {}

    virtual ~CustomList() {}

    T sum_ofPrime() const 
    {
        T sum = T();
        for (int i = 0; i < this->currentSize; i++)
            if (isPrime(this->arr[i])) sum = sum + this->arr[i];
        return sum;
    }

    // second largest distinct even number
    T secondMaxEven() const 
    {
        bool hasMax = false, hasSecond = false;
        T mx = T(), second = T();
        for (int i = 0; i < this->currentSize; i++) {
            T x = this->arr[i];
            if (!isWhole(x) || (long long)x % 2 != 0) continue;
            if (!hasMax || x > mx) {
                if (hasMax) { second = mx; hasSecond = true; }
                mx = x; hasMax = true;
            } else if (x != mx && (!hasSecond || x > second)) {
                second = x; hasSecond = true;
            }
        }
        if (!hasSecond) { cout << "No second maximum even number.\n"; return T(); }
        return second;
    }

    // second smallest distinct odd number
    T secondMinOdd() const 
    {
        bool hasMin = false, hasSecond = false;
        T mn = T(), second = T();
        for (int i = 0; i < this->currentSize; i++) {
            T x = this->arr[i];
            if (!isWhole(x) || (long long)x % 2 == 0) continue;
            if (!hasMin || x < mn) {
                if (hasMin) { second = mn; hasSecond = true; }
                mn = x; hasMin = true;
            } else if (x != mn && (!hasSecond || x < second)) {
                second = x; hasSecond = true;
            }
        }
        if (!hasSecond) { cout << "No second minimum odd number.\n"; return T(); }
        return second;
    }

    void printDuplicates() const 
    {
        bool found = false;
        for (int i = 0; i < this->currentSize; i++) 
        {
            bool seenBefore = false;
            for (int j = 0; j < i; j++)
                if (this->arr[j] == this->arr[i]) { seenBefore = true; break; }
            if (seenBefore) continue;

            int count = 0;
            for (int j = i; j < this->currentSize; j++)
                if (this->arr[j] == this->arr[i]) count++;
            if (count > 1) 
            {
                cout << this->arr[i] << " (" << count << " times)\n";
                found = true;
            }
        }
        if (!found) cout << "No duplicates.\n";
    }

  
    void rotateClockwaise(int r) {
        int mid = this->currentSize / 2;
        rotateRight(0, mid, r);
        rotateRight(mid, this->currentSize, r);
    }

    void rotateanitclockwaise(int rt) 
    {
        int mid = this->currentSize / 2;
        int len1 = mid, len2 = this->currentSize - mid;
       
        if (len1 > 0) rotateRight(0, mid, len1 - rt % len1);
        if (len2 > 0) rotateRight(mid, this->currentSize, len2 - rt % len2);
    }
};
