#include <iostream>
#include <limits>

using namespace std;

int main() {
    int departments;
    cin >> departments;

    int** salaries = new int*[departments];
    int* empCounts = new int[departments];

    for (int i = 0; i < departments; i++) {
        cin >> empCounts[i];
        salaries[i] = new int[empCounts[i]];
        for (int j = 0; j < empCounts[i]; j++) {
            cin >> salaries[i][j];
        }
    }

    for (int i = 0; i < departments; i++) {
        int maxSalary = salaries[i][0];
        for (int j = 1; j < empCounts[i]; j++) {
            if (salaries[i][j] > maxSalary)
                maxSalary = salaries[i][j];
        }
        cout << "Highest salary in department " << i + 1 << ": " << maxSalary << endl;
    }

    int maxDept = 0;
    double maxAvg = 0.0;

    for (int i = 0; i < departments; i++) {
        int sum = 0;
        for (int j = 0; j < empCounts[i]; j++) {
            sum += salaries[i][j];
        }
        double avg = (double)sum / empCounts[i];
        if (avg > maxAvg) {
            maxAvg = avg;
            maxDept = i;
        }
    }

    cout << "Department with highest average salary: " << maxDept + 1 << endl;

    for (int i = 0; i < departments; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] empCounts;

    return 0;
}
