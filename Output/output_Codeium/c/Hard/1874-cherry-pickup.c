/**https://leetcode.com/problems/cherry-pickup/ */
//You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.
//	0 means the cell is empty, so you can pass through,
//	1 means the cell contains a cherry that you can pick up and pass through, or
//	-1 means the cell contains a thorn that blocks your way.
//Return the maximum number of cherries you can collect by following the rules below:
//	Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
//	After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
//	When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
//	If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
// 
//Example 1:
//Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
//Output: 5
//Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
//4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
//Then, the player went left, up, up, left to return home, picking up one more cherry.
//The total number of cherries picked up is 5, and this is the maximum possible.
//Example 2:
//Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
//Output: 0
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 50
//	grid[i][j] is -1, 0, or 1.
//	grid[0][0] != -1
//	grid[n - 1][n - 1] != -1    
int max(int a, int b) {
    return a > b ? a : b;
}

int dp(int*** memo, int** grid, int r1, int c1, int c2, int n) {
    int r2 = r1 + c1 - c2;
    if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        return -1;
    if (r1 == n-1 && c1 == n-1) 
        return grid[r1][c1];
    if (memo[r1][c1][c2] != -2) 
        return memo[r1][c1][c2];
    
    int result = grid[r1][c1];
    if (c1 != c2) 
        result += grid[r2][c2];
    
    int temp = max(max(dp(memo, grid, r1 + 1, c1, c2, n), dp(memo, grid, r1, c1 + 1, c2, n)),
                   max(dp(memo, grid, r1 + 1, c1, c2 + 1, n), dp(memo, grid, r1, c1 + 1, c2 + 1, n)));
    
    if (temp < 0) 
        return memo[r1][c1][c2] = -1;
    
    result += temp;
    memo[r1][c1][c2] = result;
    return result;
}

int cherryPickup(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int*** memo = (int***)malloc(n * sizeof(int**));
    for (int i = 0; i < n; i++) {
        memo[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            memo[i][j] = (int*)malloc(n * sizeof(int));
            for (int k = 0; k < n; k++) {
                memo[i][j][k] = -2;
            }
        }
    }
    
    int result = dp(memo, grid, 0, 0, 0, n);
    return result < 0 ? 0 : result;
}
