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
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
    let m = board.length, n = board[0].length;
        for(let i = 0; i < m; i++){
            for(let j = 0; j < n; j++){
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1){
                    if(board[i][j] == 'O'){
                        dfs(board, i, j);
                    }
                }
            }
        }
        for(let i = 0; i < m; i++){
            for(let j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }
        function dfs(board, i, j){
            if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O'){
                return;
            }
            board[i][j] = '1';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
        return board;
};