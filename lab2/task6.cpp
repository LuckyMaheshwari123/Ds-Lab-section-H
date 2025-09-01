#include <iostream>
using namespace std;

class SafePointer {
private:
    int* ptr;

public:
    
    SafePointer() {
        ptr = new int;  
    }

    
    ~SafePointer() {
        delete ptr;
    }

    
    void setValue(int value) {
        *ptr = value;
    }

    
    int getValue() const {
        return *ptr;
    }

    
    void release() {
        delete ptr;
        ptr = nullptr;
    }
};

int main() {
    const int numStudents = 5;

    SafePointer studentMarks[numStudents];

    cout << "Enter marks for " << numStudents << " students:\n";
    for (int i = 0; i < numStudents; ++i) {
        int mark;
        cout << "Student " << i + 1 << ": ";
        cin >> mark;
        studentMarks[i].setValue(mark);
    }

    cout << "\nStored marks safely:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ": " << studentMarks[i].getValue() << endl;
    }

    return 0;
}
