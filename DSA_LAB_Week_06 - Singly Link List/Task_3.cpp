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

    int countNodes() {
        int count = 0;
        Node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    bool insertAtPosition(int value, int position) {
        if (position < 1 || position > countNodes() + 1)
            return false;

        Node* fresh = new Node(value);

        if (position == 1) {
            fresh->next = head;
            head = fresh;
            return true;
        }

        Node* curr = head;
        for (int i = 1; i < position - 1; i++)
            curr = curr->next;

        fresh->next = curr->next;
        curr->next = fresh;
        return true;
    }

    bool deleteAtPosition(int position) {
        if (position < 1 || position > countNodes())
            return false;

        if (position == 1) {
            Node* del = head;
            head = head->next;
            delete del;
            return true;
        }

        Node* curr = head;
        for (int i = 1; i < position - 1; i++)
            curr = curr->next;

        Node* del = curr->next;
        curr->next = del->next;
        delete del;
        return true;
    }

    int search(int value) {
        int position = 1;
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == value)
                return position;
            curr = curr->next;
            position++;
        }
        return -1;
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
    int choice, value, position;

    do {
        cout << "\n===== SINGLY LINKED LIST MENU =====\n";
        cout << "1. Insert node at a specific position\n";
        cout << "2. Delete node at a specific position\n";
        cout << "3. Search for an element\n";
        cout << "4. Count total number of nodes\n";
        cout << "5. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position (1 to " << myList.countNodes() + 1 << "): ";
            cin >> position;
            if (myList.insertAtPosition(value, position))
                cout << "Inserted.\n";
            else
                cout << "Invalid position.\n";
        }
        else if (choice == 2) {
            cout << "Enter position (1 to " << myList.countNodes() << "): ";
            cin >> position;
            if (myList.deleteAtPosition(position))
                cout << "Deleted.\n";
            else
                cout << "Invalid position.\n";
        }
        else if (choice == 3) {
            cout << "Enter value to search: ";
            cin >> value;
            position = myList.search(value);
            if (position == -1)
                cout << value << " is not in the list.\n";
            else
                cout << value << " found at position " << position << ".\n";
        }
        else if (choice == 4) {
            cout << "Total nodes: " << myList.countNodes() << "\n";
        }
        else if (choice == 5) {
            myList.display();
        }
        else if (choice != 0) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
