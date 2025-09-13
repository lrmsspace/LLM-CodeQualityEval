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
	int n = *boardColSize;
	
	// mark the 'O' regions connected to the edge as 'N'
	for (int i = 0; i < m; i++) {
		if (board[i][0] == 'O') dfs(board, i, 0, m, n);
		if (board[i][n-1] == 'O') dfs(board, i, n-1, m, n);
	}
	for (int i = 0; i < n; i++) {
		if (board[0][i] == 'O') dfs(board, 0, i, m, n);
		if (board[m-1][i] == 'O') dfs(board, m-1, i, m, n);
	}
	
	// capture the surrounded regions
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'O') board[i][j] = 'X';
			if (board[i][j] == 'N') board[i][j] = 'O';
		}
	}
    
    return;
}