#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
    for (int i = 0; i < 9; i++) {
    if (board[row][i] == val) return false;
        if (board[i][col] == val) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
      for (char val = '1'; val <= '9'; val++) {
                    if (isSafe(row, col, board, val)) {
           board[row][col] = val;
       if (solve(board)) return true;
        board[row][col] = '.';
                    }
         }
   return false;
            }
    }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}
int main() {
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter the Sudoku board (use . for empty cells):\n";
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    solveSudoku(board);

    cout << "\nSolved Sudoku:\n";
    printBoard(board);
    return 0;
}