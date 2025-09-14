/**https://leetcode.com/problems/sudoku-solver/ */
//Write a program to solve a Sudoku puzzle by filling the empty cells.
//A sudoku solution must satisfy all of the following rules:
//	Each of the digits 1-9 must occur exactly once in each row.
//	Each of the digits 1-9 must occur exactly once in each column.
//	Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//The '.' character indicates empty cells.
// 
//Example 1:
//Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
//Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
//Explanation: The input board is shown above and the only valid solution is shown below:
// 
//Constraints:
//	board.length == 9
//	board[i].length == 9
//	board[i][j] is a digit or '.'.
//	It is guaranteed that the input board has only one solution.
class Solution {
    public void solveSudoku(char[][] board) {
        solve(board, 0, 0);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        
        // Helper function to solve the Sudoku puzzle
        boolean solve(char[][] board, int row, int col) {
            // If we have reached the end of the board, return true
            if (row == 9) {
                return true;
            }
            
            // If the current cell is empty, find the next empty cell

            if (board[row][col] == '.') {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, (char) (num + '0'))) {
                        board[row][col] = (char) (num + '0');
                        // Recursively solve the next cell
                        if (solve(board, getNextRowCol(row, col).row, getNextRowCol(row, col).col)) {
                            return true;
                        }
                        // If the current cell doesn't lead to a valid solution, backtrack
                        board[row][col] = '.';
                    }
    
                    // If there are no valid numbers for the current cell, return false
                    if (num == 9) {
                        return false;
                    }
                }
    
                // If we reach this point, it means that no valid number can be placed in the current cell
                return false;
            } else {
                // Recursively solve the next cell
                return solve(board, getNextRowCol(row, col).row, getNextRowCol(row, col).col);
            }
            
            // If the current cell has been filled, move to the next cell
            return solve(board, getNextRowCol(row, col).row, getNextRowCol(row, col).col);
        }
    }
}