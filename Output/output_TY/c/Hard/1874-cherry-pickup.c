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
int cherryPickup(int** grid, int gridSize, int* gridColSize){
    int n = gridSize;
    int m = gridColSize[0];
    int dp[n][m][m];
    memset(dp, 0, sizeof(dp));
    dp[0][0][m-1] = grid[0][0] + grid[0][m-1];
    for (int i = 1; i < n; i++) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int max_val = 0;
                for (int dj1= -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int j11 = j1 + dj1;
                        int j22 = j2 + dj2;
                        if (j11 >= 0 && j11 < m && j22 >= 0 && j22 < m) {
                            int val = dp[i-1][j11][j22] + grid[i][j1] + grid[i][j2];
                        }
                    }
}
            }
        }
    }
    return dp[n-1][m-2][m-1];
}