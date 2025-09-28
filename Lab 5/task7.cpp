```cpp
#include <iostream>
using namespace std;

#define MAX 20  // maximum N supported

void printSolution(int board[MAX][MAX], int N) {
    static int solutionCount = 1;
    cout << "Solution " << solutionCount++ << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}


bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    int i, j;


    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

   
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}


void solveNQUtil(int board[MAX][MAX], int row, int N) {

    if (row == N) {
        printSolution(board, N);
        return;
    }


    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solveNQUtil(board, row + 1, N);
            board[row][col] = 0; // backtrack
        }
    }
}


void solveNQ(int N) {
    int board[MAX][MAX] = {0};
    solveNQUtil(board, 0, N);
}

int main() {
    int N;
    cout << "Enter value of N: ";
    cin >> N;

    if (N < 1 || N > MAX) {
        cout << "Please enter N between 1 and " << MAX << endl;
        return 0;
    }

    solveNQ(N);
    return 0;
}
```
