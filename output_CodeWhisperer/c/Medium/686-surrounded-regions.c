/**https://leetcode.com/problems/surrounded-regions/ */
//You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
//	Connect: A cell is connected to adjacent cells horizontally or vertically.
//	Region: To form a region connect every 'O' cell.
//	Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
//A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.
// 
//Example 1:
//Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
//Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//Explanation:
//In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
//Example 2:
//Input: board = [["X"]]
//Output: [["X"]]
// 
//Constraints:
//	m == board.length
//	n == board[i].length
//	1 <= m, n <= 200
//	board[i][j] is 'X' or 'O'.
void solve(char** board, int boardSize, int* boardColSize) {
    int m = boardSize;
    int n = boardColSize[0];
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = '1';
            }
        }
    }
    for (i = 0; i < m; i++) {
        if (board[i][0] == '1') {
            dfs(board, m, n, i, 0);
        }
        if (board[i][n - 1] == '1') {
            dfs(board, m, n, i, n - 1);
        }
    }
    for (j = 0; j < n; j++) {
        if (board[0][j] == '1') {
            dfs(board, m, n, 0, j);
        }
        if (board[m - 1][j] == '1') {
            dfs(board, m, n, m - 1, j);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == '1') {
                board[i][j] = 'X';
            }
        }
    }   

}