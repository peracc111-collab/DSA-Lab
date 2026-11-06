#include <iostream>
#include <string>
using namespace std;

class StudentNode {
public:
    string name;
    int priority;
    StudentNode* next;

    StudentNode(string studentName, int studentPriority) {
        name = studentName;
        priority = studentPriority;
        next = nullptr;
    }
};

class ReservationList {
private:
    StudentNode* head;

    void insertInOrder(StudentNode* fresh) {
        if (head == nullptr || fresh->priority < head->priority) {
            fresh->next = head;
            head = fresh;
            return;
        }
        StudentNode* curr = head;
        while (curr->next != nullptr && curr->next->priority <= fresh->priority)
            curr = curr->next;

        fresh->next = curr->next;
        curr->next = fresh;
    }

public:
    ReservationList() {
        head = nullptr;
    }

    ~ReservationList() {
        StudentNode* curr = head;
        while (curr != nullptr) {
            StudentNode* del = curr;
            curr = curr->next;
            delete del;
        }
    }

    void addStudent(string name, int priority = 3) {
        if (priority < 1 || priority > 3)
            priority = 3;
        StudentNode* fresh = new StudentNode(name, priority);
        insertInOrder(fresh);
    }

    bool removeStudent(string name) {
        if (head == nullptr)
            return false;

        if (head->name == name) {
            StudentNode* del = head;
            head = head->next;
            delete del;
            return true;
        }

        StudentNode* curr = head;
        while (curr->next != nullptr && curr->next->name != name)
            curr = curr->next;

        if (curr->next == nullptr)
            return false;

        StudentNode* del = curr->next;
        curr->next = del->next;
        delete del;
        return true;
    }

    bool updatePriority(string name, int newPriority) {
        if (newPriority < 1 || newPriority > 3)
            return false;

        StudentNode* prev = nullptr;
        StudentNode* curr = head;
        while (curr != nullptr && curr->name != name) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr)
            return false;

        if (prev == nullptr)
            head = curr->next;
        else
            prev->next = curr->next;

        curr->priority = newPriority;
        insertInOrder(curr);
        return true;
    }

    void display() {
        if (head == nullptr) {
            cout << "  No reservations.\n";
            return;
        }
        int number = 1;
        StudentNode* curr = head;
        while (curr != nullptr) {
            cout << "  " << number << ". " << curr->name << "  [";
            if (curr->priority == 1)
                cout << "Research";
            else if (curr->priority == 2)
                cout << "Assignment";
            else
                cout << "Casual reading";
            cout << "]\n";
            curr = curr->next;
            number++;
        }
    }

    int countStudents() {
        int count = 0;
        StudentNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    string removeFront() {
        if (head == nullptr)
            return "";
        StudentNode* del = head;
        string name = del->name;
        head = head->next;
        delete del;
        return name;
    }
};

class Book {
public:
    string title;
    ReservationList waitList;

    Book(string bookTitle) {
        title = bookTitle;
    }

    void returnBook() {
        string served = waitList.removeFront();
        if (served == "")
            cout << "\"" << title << "\" returned. Nobody is waiting.\n";
        else
            cout << "\"" << title << "\" returned. Given to: " << served << "\n";
    }

    void showReservations() {
        cout << "Reservations for \"" << title << "\":\n";
        waitList.display();
        cout << "  Students waiting: " << waitList.countStudents() << "\n";
    }
};

int main() {
    Book book1("Data Structures");
    Book book2("Database Systems");

    cout << "===== BOOK 1 =====\n";
    cout << "\n--- Students join (priority: 1=Research, 2=Assignment, 3=Casual) ---\n";
    book1.waitList.addStudent("Ali");
    book1.waitList.addStudent("Sara", 2);
    book1.waitList.addStudent("Usman", 3);
    book1.waitList.addStudent("Hina", 1);
    book1.waitList.addStudent("Bilal", 3);
    book1.showReservations();

    cout << "\n--- Usman cancels ---\n";
    if (book1.waitList.removeStudent("Usman"))
        cout << "Usman removed.\n";
    book1.showReservations();

    cout << "\n--- Bilal's work becomes a research project: priority 3 -> 1 ---\n";
    book1.waitList.updatePriority("Bilal", 1);
    book1.showReservations();

    cout << "\n--- Book returned ---\n";
    book1.returnBook();
    book1.showReservations();

    cout << "\n===== BOOK 2 =====\n";
    cout << "\n--- Students join ---\n";
    book2.waitList.addStudent("Zainab");
    book2.waitList.addStudent("Omer", 2);
    book2.waitList.addStudent("Ayesha");
    book2.showReservations();

    cout << "\n--- Ayesha has an assignment: priority 3 -> 2 ---\n";
    book2.waitList.updatePriority("Ayesha", 2);
    book2.showReservations();

    cout << "\n--- Book returned twice ---\n";
    book2.returnBook();
    book2.returnBook();
    book2.showReservations();

    return 0;
}
