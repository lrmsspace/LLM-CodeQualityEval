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
int cherryPickup(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;

    int dp[n][n][n];
    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = grid[0][0];

    for (int k = 1; k < 2 * n - 1; k++) {
        for (int i1 = 0; i1 < n; i1++) {
            for (int i2 = 0; i2 < n; i2++) {
                int j1 = k - i1;
                int j2 = k - i2;

                if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
                    continue;
                }

                int cherry = grid[i1][j1];
                if (i1 != i2) {
                    cherry += grid[i2][j2];
                }

                int max = 0;
                for (int x = i1 - 1; x <= i1; x++) {
                    for (int y = i2 - 1; y <= i2; y++) {
                        if (x >= 0 && y >= 0) {
                            max = fmax(max, dp[x][y][k - 1]);
                        }
                    }
                }

                if (max != -1) {
                    dp[i1][i2][k] = max + cherry;
                }
            }
        }
    }
    int ans = 0;

    for (int i1 = 0; i1 < n; i1++) {
        for (int i2 = 0; i2 < n; i2++) {
            ans = fmax(ans, dp[i1][i2][2 * n - 2]);
        }
    }

    return fmax(0, ans);    
    
}