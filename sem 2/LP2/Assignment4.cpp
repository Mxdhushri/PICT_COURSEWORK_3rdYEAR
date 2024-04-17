// save file name as "assignment4" only
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class NQueen {
public:
    int N;
    vector<vector<int>> board; // Using vector of vectors for dynamic 2D array

    // Constructor to initialize the board size
    NQueen(int n) : N(n), board(n, vector<int>(n, 0)) {}

    void printSolution() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << (board[i][j] == 1 ? "Q " : ". ");
            cout << endl;
        }
        cout<<endl;
    }

    bool isSafe(int row, int col) {
        int i, j;

        // Check this row on left side
        for (i = 0; i < col; i++)
            if (board[row][i] == 1)
                return false;

        // Check upper diagonal on left side
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;

        // Check lower diagonal on left side
        for (i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    bool solveNQUtil(int col) {
        // Base case: If all queens are placed, return true
        if (col >= N)
            return true;

        for (int i = 0; i < N; i++) {
     
            if (isSafe(i, col)) {
               
                board[i][col] = 1;
                cout<<"Queen placed"<<endl;
                printSolution();
                if (solveNQUtil(col + 1))
                    return true;

                // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
                board[i][col] = 0; // BACKTRACK
                cout<<"Cannot place the queen so back track"<<endl;
                printSolution();
            }
        }

        // If the queen cannot be placed in any row in this column col, then return false
        return false;
    }

    // Main function to solve N-Queen problem
    bool solveNQ() {
        if (!solveNQUtil(0)) {
            cout << "Solution does not exist" << endl;
            return false;
        }

        // Print the solution
        cout << "Solution Exists:" << endl;
        printSolution();
        return true;
    }
};

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    NQueen q(n);
    q.solveNQ();

    return 0;
}