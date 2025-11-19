#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int severity;
    int arrival;
    Patient* next;
};

class HospitalPQ {
private:
    Patient* head;

    // Compare A has higher priority than B?
    bool higherPriority(Patient* A, Patient* B) {
        if (A->severity > B->severity)
            return true;
        if (A->severity < B->severity)
            return false;
        return A->arrival < B->arrival;  
    }

public:
    HospitalPQ() {
        head = NULL;
    }

   
    void addPatient(string name, int severity, int arrival) {
        Patient* newP = new Patient;
        newP->name = name;
        newP->severity = severity;
        newP->arrival = arrival;
        newP->next = NULL;

     
        if (head == NULL || higherPriority(newP, head)) {
            newP->next = head;
            head = newP;
            return;
        }

        Patient* curr = head;
        while (curr->next != NULL && !higherPriority(newP, curr->next)) {
            curr = curr->next;
        }

        newP->next = curr->next;
        curr->next = newP;
    }

    
    Patient getNextPatient() {
        Patient empty = {"NONE", -1, -1, NULL};

        if (head == NULL) {
            cout << "No patients waiting.\n";
            return empty;
        }

        Patient* temp = head;
        head = head->next;

        Patient result = *temp;
        delete temp;

        return result;
    }

    
    void updateSeverity(string name, int newSeverity) {
        if (head == NULL) {
            cout << "No patients.\n";
            return;
        }

        Patient* curr = head;
        Patient* prev = NULL;

       
        while (curr != NULL && curr->name != name) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Patient not found.\n";
            return;
        }

        
        if (prev == NULL)
            head = curr->next;
        else
            prev->next = curr->next;


        curr->severity = newSeverity;
        curr->next = NULL;

       
        if (head == NULL || higherPriority(curr, head)) {
            curr->next = head;
            head = curr;
            return;
        }

        Patient* temp = head;
        while (temp->next != NULL && !higherPriority(curr, temp->next)) {
            temp = temp->next;
        }

        curr->next = temp->next;
        temp->next = curr;
    }

    void displayAll() {
        if (head == NULL) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "\nPatients from highest to lowest priority:\n";

        Patient* curr = head;
        while (curr != NULL) {
            cout << curr->name
                 << " | Severity: " << curr->severity
                 << " | Arrival: " << curr->arrival << endl;
            curr = curr->next;
        }
        cout << endl;
    }
};
int main() {
    HospitalPQ pq;
    int arrival = 0;

    pq.addPatient("Lucky", 5, arrival++);
    pq.addPatient("Asad", 9, arrival++);
    pq.addPatient("Babloo", 9, arrival++);
    pq.addPatient("Muna", 3, arrival++);

    pq.displayAll();

    cout << "\nNext patient: ";
    Patient p = pq.getNextPatient();
    cout << p.name << " (Severity " << p.severity << ")\n";

    pq.updateSeverity("Mary", 10);

    pq.displayAll();

    return 0;
}
