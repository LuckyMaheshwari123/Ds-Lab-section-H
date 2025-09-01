#include <iostream>
using namespace std;

int* allocateMemory(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    return arr;
}

int* resizeMemory(int* ptr, int oldsize, int newsize) {
    if (oldsize == newsize) {
        return ptr;
    }


    int* newarr = new int[newsize];
    int limit = (oldsize < newsize) ? oldsize : newsize;

    for (int i = 0; i < limit; i++) {
        newarr[i] = ptr[i];
    }
    delete[] ptr;
    return newarr;
}

void input(int* ptr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter the month " << i + 1 << " expenses: ";
        cin >> ptr[i];
    }
}

int getTotal(int* ptr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += ptr[i];
    }
    return total;
}

int getAverage(int* ptr, int n) {
    if (n == 0) return 0;  // Avoid division by zero
    int total = getTotal(ptr, n);
    return total / n;
}

int main() {
    int n;
    cout << "Enter how many months of expenses you want to store: ";
    cin >> n;

    int* allocate = allocateMemory(n);
    input(allocate, n);

    int tot = getTotal(allocate, n);
    int av = getAverage(allocate, n);

    cout << "The total is: " << tot << endl;
    cout << "The Average is: " << av << endl;

    int choice;
    cout << "Do you want to add more months (1 for yes, 0 for no)? ";
    cin >> choice;
    
    while (choice == 1) {
        int am;
        cout << "Enter how many months: ";
        cin >> am;
        
        int newsize=n+am;
        // Resize memory and update pointer
        int* np = resizeMemory(allocate, n, newsize);
        allocate = np;  // Update the pointer to the new memory
        
        if (newsize > n) {
            cout << "Enter further elements: ";
            for (int i = n; i < newsize; i++) {
                cin >> allocate[i];
            }
        }

        n = newsize;  // Update the size to the new size
        tot = getTotal(allocate, n);  // Recalculate total and average
        av = getAverage(allocate, n);
        cout << "The updated total is: " << tot << endl;
        cout << "The updated Average is: " << av << endl;

        cout << "Do you want to add more months (1 for yes, 0 for no)? ";
        cin >> choice;
    }

    delete[] allocate;
    cout << "Thanks for using!" << endl;

    return 0;
}
