#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* del = curr;
            curr = curr->next;
            delete del;
        }
    }

    void insertAtBeginning(int value) {
        Node* fresh = new Node(value);
        fresh->next = head;
        head = fresh;
    }

    void insertAtEnd(int value) {
        Node* fresh = new Node(value);

        if (head == nullptr) {
            head = fresh;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = fresh;
    }

    bool deleteByValue(int value) {
        if (head == nullptr)
            return false;

        if (head->data == value) {
            Node* del = head;
            head = head->next;
            delete del;
            return true;
        }

        Node* curr = head;
        while (curr->next != nullptr && curr->next->data != value)
            curr = curr->next;

        if (curr->next == nullptr)
            return false;

        Node* del = curr->next;
        curr->next = del->next;
        delete del;
        return true;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList myList;

    cout << "Insert at end: 20, 30, 40\n";
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);
    myList.insertAtEnd(40);
    myList.display();

    cout << "\nInsert at beginning: 10\n";
    myList.insertAtBeginning(10);
    myList.display();

    cout << "\nDelete value 30 (middle node)\n";
    if (myList.deleteByValue(30))
        cout << "Deleted.\n";
    myList.display();

    cout << "\nDelete value 10 (first node)\n";
    if (myList.deleteByValue(10))
        cout << "Deleted.\n";
    myList.display();

    cout << "\nDelete value 40 (last node)\n";
    if (myList.deleteByValue(40))
        cout << "Deleted.\n";
    myList.display();

    cout << "\nDelete value 99 (not in the list)\n";
    if (!myList.deleteByValue(99))
        cout << "Value 99 not found.\n";
    myList.display();

    return 0;
}
