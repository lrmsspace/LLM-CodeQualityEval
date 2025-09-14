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
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    solve(board);
    
    function solve(board) {
        for (let i = 0; i < 9; i++) {
            for (let j = 0; j < 9; j++) {
                if (board[i][j] === '.') {
                    for (let k = 1; k <= 9; k++) {
                        if (isValid(board, i, j, k)) {
                            board[i][j] = String(k);
                            if (solve(board)) return true; // if a valid solution is found, return true
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // if no valid solution is found, return false
                }
            }
        }
        return true; // if all cells are filled, return true
    }
    
    function isValid(board, row, col, num) {
        // Check row and column
        for (let i = 0; i < 9; i++) {
            if (board[row][i] === String(num) || board[i][col] === String(num)) return false;
        }
        
        // Check 3x3 sub-box
        let startRow = Math.floor(row / 3) * 3;
        let startCol = Math.floor(col / 3) * 3;
        for (let i = startRow; i < startRow + 3; i++) {
            for (let j = startCol; j < startCol + 3; j++) {
                if (board[i][j] === String(num)) return false;
            }
        }
        
        return true;
    }

    return board; // return the solved Sudoku board
    
};