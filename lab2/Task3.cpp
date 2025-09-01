#include <iostream>
using namespace std;

int main() {
    int numStudents;
    cin >> numStudents;

    int** marks = new int*[numStudents];
    int* numCourses = new int[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cin >> numCourses[i];
        marks[i] = new int[numCourses[i]];
        for (int j = 0; j < numCourses[i]; j++) {
            cin >> marks[i][j];
        }
    }

    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        for (int j = 0; j < numCourses[i]; j++) {
            sum += marks[i][j];
        }
        float average = static_cast<float>(sum) / numCourses[i];
        cout << "Student " << i + 1 << " average: " << average << endl;
    }

    for (int i = 0; i < numStudents; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] numCourses;

    return 0;
}
