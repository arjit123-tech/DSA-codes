#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printsudoku(int sudoku[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int sudoku[9][9], int row, int col, int digit) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == digit) return false;
    }
    // Check column
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == digit) return false;
    }
    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[startRow + i][startCol + j] == digit) return false;
        }  
    }
    return true;
}

bool sudokusolver(int sudoku[9][9], int row, int col) {
    // If we have reached the end of the board, print and return true
    if (row == 9) {
        printsudoku(sudoku);
        return true;
    }

    // If column is at end, move to next row
    if (col == 9) {
        return sudokusolver(sudoku, row + 1, 0);
    }

    // If cell is already filled, move to next cell
    if (sudoku[row][col] != 0) {
        return sudokusolver(sudoku, row, col + 1);
    }

    // Try all digits
    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;
            if (sudokusolver(sudoku, row, col + 1)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}
int main() {
    int sudoku[9][9] = {
        {0,0,8,0,0,0,0,0,0},
        {4,9,0,1,5,7,0,0,2},
        {0,0,3,0,0,4,1,9,0},
        {1,8,5,0,6,0,0,2,0},
        {0,0,0,0,2,0,0,6,0},
        {9,6,0,4,0,5,3,0,0},
        {0,3,0,0,7,2,0,0,4},
        {0,4,9,0,3,0,0,5,7},
        {8,2,7,0,0,9,0,1,3}
    };
    sudokusolver(sudoku, 0, 0);
    return 0;
}