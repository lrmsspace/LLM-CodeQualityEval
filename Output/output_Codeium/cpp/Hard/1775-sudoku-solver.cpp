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
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> boxes(9, vector<bool>(10, false));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int num = c - '0';
                    int boxIndex = (i / 3) * 3 + j / 3;
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                }
            }
        }
        
        function<bool(int, int)> backtrack = [&](int i, int j) {
            if (i == 9) return true;
            if (j == 9) return backtrack(i + 1, 0);
            if (board[i][j] != '.') return backtrack(i, j + 1);
            
            int boxIndex = (i / 3) * 3 + j / 3;
            for (int num = 1; num <= 9; num++) {
                if (!rows[i][num] && !cols[j][num] && !boxes[boxIndex][num]) {
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                    board[i][j] = '0' + num;
                    if (backtrack(i, j + 1)) return true;
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = false;
                    board[i][j] = '.';
                }
            }
            return false;
        };
        backtrack(0, 0);
            
    }
};