#include <iostream>
using namespace std;

// Function to input matrix
void inputMatrix(int** matrix, int rows, int cols) {
    cout << "Enter matrix elements (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> matrix[i][j];
}

// Function to display matrix
void displayMatrix(int** matrix, int rows, int cols) {
    cout << "\nMatrix in normal form:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

// Function to convert and display matrix in compressed form
void displayCompressedForm(int** matrix, int rows, int cols) {
    int nonZero = 0;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (matrix[i][j] != 0)
                ++nonZero;

    
    int** compressed = new int*[nonZero];
    for (int i = 0; i < nonZero; ++i)
        compressed[i] = new int[3];

    
    int k = 0;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (matrix[i][j] != 0) {
                compressed[k][0] = i;
                compressed[k][1] = j;
                compressed[k][2] = matrix[i][j];
                ++k;
            }

    /
    cout << "\nCompressed form (row, col, value):\n";
    for (int i = 0; i < nonZero; ++i)
        cout << compressed[i][0] << " " << compressed[i][1] << " " << compressed[i][2] << endl;

    // Free memory
    for (int i = 0; i < nonZero; ++i)
        delete[] compressed[i];
    delete[] compressed;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    // Allocate memory for matrix
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[cols];

    inputMatrix(matrix, rows, cols);
    displayMatrix(matrix, rows, cols);
    displayCompressedForm(matrix, rows, cols);

    
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
