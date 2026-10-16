#include <iostream>
#include "CustomList.h"   // includes MyList.h, which includes List.h
using namespace std;

int main() {
    int cap;
    cout << "Enter list capacity: ";
    cin >> cap;
    CustomList<int> list(cap);

    int choice;
    do {
        cout << "\n--- Menu ---\n"
             << " 1. Add at first index\n 2. Add at last index\n"
             << " 3. Remove from start\n 4. Remove from end\n"
             << " 5. Insert at index\n 6. Search\n 7. Last element\n"
             << " 8. Empty?\n 9. Full?\n10. Size\n11. Display\n"
             << "12. Copy list (copy constructor) and display\n"
             << "13. Sum of primes\n14. Second max even\n15. Second min odd\n"
             << "16. Print duplicates\n17. Rotate clockwise\n18. Rotate anti-clockwise\n"
             << " 0. Exit\nChoice: ";
        cin >> choice;
        int v, idx;
        switch (choice) {
            case 1: cout << "Value: "; cin >> v; list.addElementAtFirstIndex(v); break;
            case 2: cout << "Value: "; cin >> v; list.addElementAtLastIndex(v); break;
            case 3: list.removeElementFromStart(); break;
            case 4:
                if (!list.empty()) cout << "Removed: " << list.removeElementFromEnd() << endl;
                else cout << "List is empty.\n";
                break;
            case 5:
                cout << "Index and value: "; cin >> idx >> v;
                cout << (list.insertAt(idx, v) ? "Inserted.\n" : "Insert failed.\n");
                break;
            case 6:
                cout << "Value: "; cin >> v;
                cout << (list.search(v) ? "Found.\n" : "Not found.\n");
                break;
            case 7:
                if (!list.empty()) cout << "Last: " << list.last() << endl;
                else cout << "List is empty.\n";
                break;
            case 8: cout << (list.empty() ? "Yes, empty.\n" : "No, not empty.\n"); break;
            case 9: cout << (list.full() ? "Yes, full.\n" : "No, not full.\n"); break;
            case 10: cout << "Size: " << list.size() << endl; break;
            case 11: list.display(); break;
            case 12: { CustomList<int> copy(list); cout << "Copy: "; copy.display(); break; }
            case 13: cout << "Sum of primes: " << list.sum_ofPrime() << endl; break;
            case 14: v = list.secondMaxEven(); cout << "Second max even: " << v << endl; break;
            case 15: v = list.secondMinOdd(); cout << "Second min odd: " << v << endl; break;
            case 16: list.printDuplicates(); break;
            case 17: cout << "Rotations: "; cin >> v; list.rotateClockwaise(v); list.display(); break;
            case 18: cout << "Rotations: "; cin >> v; list.rotateanitclockwaise(v); list.display(); break;
            case 0: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
