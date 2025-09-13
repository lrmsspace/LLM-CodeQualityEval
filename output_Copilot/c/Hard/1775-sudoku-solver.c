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
void solveSudoku(char** board, int boardSize, int* boardColSize) {
    int row[9][9] = {0}, col[9][9] = {0}, box[3][3][9] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            int num = board[i][j] - '1';
            row[i][num]++;
            col[j][num]++;
            box[i / 3][j / 3][num]++;
        }
    }
    void dfs(int i, int j) {
        if (i == 9) return;
        if (j == 9) {
            dfs(i + 1, 0);
            return;
        }
        if (board[i][j] != '.') {
            dfs(i, j + 1);
            return;
        }
        for (int num = 0; num < 9; num++) {
            if (row[i][num] || col[j][num] || box[i / 3][j / 3][num]) continue;
            row[i][num]++;
            col[j][num]++;
            box[i / 3][j / 3][num]++;
            board[i][j] = num + '1';
            dfs(i, j + 1);
            if (board[i][j] == '.') {
                row[i][num]--;
                col[j][num]--;
                box[i / 3][j / 3][num]--;
            }
        }
        board[i][j] = '.';
    }
    dfs(0, 0);    
}