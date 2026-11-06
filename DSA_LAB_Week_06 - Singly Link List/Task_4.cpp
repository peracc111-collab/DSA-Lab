#include <iostream>
#include <string>
using namespace std;

class PatientNode {
public:
    string name;
    PatientNode* next;

    PatientNode(string patientName) {
        name = patientName;
        next = nullptr;
    }
};

class PatientQueue {
private:
    PatientNode* head;

public:
    PatientQueue() {
        head = nullptr;
    }

    ~PatientQueue() {
        PatientNode* curr = head;
        while (curr != nullptr) {
            PatientNode* del = curr;
            curr = curr->next;
            delete del;
        }
    }

    void addPatient(string name) {
        PatientNode* fresh = new PatientNode(name);

        if (head == nullptr) {
            head = fresh;
            return;
        }
        PatientNode* curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = fresh;
    }

    bool removePatient(string name) {
        if (head == nullptr)
            return false;

        if (head->name == name) {
            PatientNode* del = head;
            head = head->next;
            delete del;
            return true;
        }

        PatientNode* curr = head;
        while (curr->next != nullptr && curr->next->name != name)
            curr = curr->next;

        if (curr->next == nullptr)
            return false;

        PatientNode* del = curr->next;
        curr->next = del->next;
        delete del;
        return true;
    }

    void display() {
        if (head == nullptr) {
            cout << "  No patients waiting.\n";
            return;
        }
        int number = 1;
        PatientNode* curr = head;
        while (curr != nullptr) {
            cout << "  " << number << ". " << curr->name << "\n";
            curr = curr->next;
            number++;
        }
    }

    int countPatients() {
        int count = 0;
        PatientNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
};

int main() {
    PatientQueue clinic;

    cout << "--- Patients arrive: Ali, Sara, Usman, Hina ---\n";
    clinic.addPatient("Ali");
    clinic.addPatient("Sara");
    clinic.addPatient("Usman");
    clinic.addPatient("Hina");
    clinic.display();
    cout << "Patients in queue: " << clinic.countPatients() << "\n";

    cout << "\n--- Sara cancels her appointment ---\n";
    if (clinic.removePatient("Sara"))
        cout << "Sara removed.\n";
    clinic.display();
    cout << "Patients in queue: " << clinic.countPatients() << "\n";

    cout << "\n--- Bilal tries to cancel (he is not in the queue) ---\n";
    if (!clinic.removePatient("Bilal"))
        cout << "Bilal not found in the queue.\n";

    cout << "\n--- Ali (first patient) cancels ---\n";
    clinic.removePatient("Ali");
    clinic.display();

    cout << "\n--- New patient Zainab arrives ---\n";
    clinic.addPatient("Zainab");
    clinic.display();
    cout << "Patients in queue: " << clinic.countPatients() << "\n";

    return 0;
}
