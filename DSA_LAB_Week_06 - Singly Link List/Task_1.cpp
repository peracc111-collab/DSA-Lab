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

    void createNode(int value) {
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

    myList.createNode(10);
    myList.createNode(20);
    myList.createNode(30);
    myList.createNode(40);

    cout << "Linked list: ";
    myList.display();

    return 0;
}
