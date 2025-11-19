#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Patient {
    string name;
    int severity;
    int arrival;
};

class HospitalPQ {
private:
    Patient heap[MAX];
    int size;

   
    bool higherPriority(Patient A, Patient B) {
        if (A.severity > B.severity)
            return true;
        if (A.severity < B.severity)
            return false;
        return A.arrival < B.arrival;   
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (!higherPriority(heap[i], heap[parent]))
                break;

            Patient temp = heap[i];
            heap[i] = heap[parent];
            heap[parent] = temp;

            i = parent;
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && higherPriority(heap[left], heap[largest]))
                largest = left;

            if (right < size && higherPriority(heap[right], heap[largest]))
                largest = right;

            if (largest == i)
                break;

            Patient temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;

            i = largest;
        }
    }

public:
    HospitalPQ() { size = 0; }

   
    void addPatient(string name, int severity, int arrival) {
        if (size >= MAX) {
            cout << "Queue full!\n";
            return;
        }

        heap[size].name = name;
        heap[size].severity = severity;
        heap[size].arrival = arrival;

        heapifyUp(size);
        size++;
    }

  
    Patient getNextPatient() {
        if (size == 0) {
            cout << "No patients waiting.\n";
            Patient none = {"NONE", -1, -1};
            return none;
        }

        Patient top = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return top;
    }

  
    void updateSeverity(string name, int newSeverity) {
        int i;
        for (i = 0; i < size; i++) {
            if (heap[i].name == name) {
                heap[i].severity = newSeverity;
                heapifyUp(i);
                heapifyDown(i);
                return;
            }
        }
        cout << "Patient not found.\n";
    }

    
    void displayAll() {
        if (size == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        // Create temp copy of heap
        Patient temp[MAX];
        int tempSize = size;
        int i;

        for (i = 0; i < size; i++)
            temp[i] = heap[i];

        cout << "\nPatients from highest to lowest priority:\n";

        // Extract max repeatedly from temp
        while (tempSize > 0) {
            // 1. Get max = temp[0]
            Patient best = temp[0];

            cout << best.name << " | Severity: " << best.severity
                 << " | Arrival: " << best.arrival << endl;

            // 2. Replace root with last
            temp[0] = temp[tempSize - 1];
            tempSize--;

         
            int idx = 0;
            while (true) {
                int left = 2 * idx + 1;
                int right = 2 * idx + 2;
                int largest = idx;

                if (left < tempSize && 
                    (temp[left].severity > temp[largest].severity ||
                    (temp[left].severity == temp[largest].severity &&
                     temp[left].arrival < temp[largest].arrival)))
                {
                    largest = left;
                }

                if (right < tempSize && 
                    (temp[right].severity > temp[largest].severity ||
                    (temp[right].severity == temp[largest].severity &&
                     temp[right].arrival < temp[largest].arrival)))
                {
                    largest = right;
                }

                if (largest == idx)
                    break;

                Patient t = temp[idx];
                temp[idx] = temp[largest];
                temp[largest] = t;

                idx = largest;
            }
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

    pq.updateSeverity("Muna", 10);

    pq.displayAll();

    return 0;
}

